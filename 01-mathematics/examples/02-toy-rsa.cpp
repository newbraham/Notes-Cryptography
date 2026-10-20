// Educational RSA demonstration.
//
// This program uses deliberately small integers and textbook RSA without
// padding. It explains the arithmetic; it must not be used for security.

#include <cstdint>
#include <exception>
#include <iomanip>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

namespace {

using Integer = std::uint64_t;
using SignedInteger = std::int64_t;

constexpr Integer kLargestInputPrime = 1'000'000;

struct BezoutResult {
    SignedInteger gcd;
    SignedInteger coefficient_a;
    SignedInteger coefficient_b;
};

Integer parse_integer(const char* text, const std::string& name) {
    std::string value{text};
    std::size_t parsed_characters = 0;
    Integer result = 0;

    if (value.empty() || value.front() == '-') {
        throw std::invalid_argument(name + " must be a nonnegative integer");
    }

    try {
        result = std::stoull(value, &parsed_characters);
    } catch (const std::exception&) {
        throw std::invalid_argument(name + " must be a nonnegative integer");
    }

    if (parsed_characters != value.size()) {
        throw std::invalid_argument(name + " must be a nonnegative integer");
    }

    return result;
}

bool is_prime_with_trace(Integer candidate, const std::string& name) {
    std::cout << "Testing whether " << name << " = " << candidate
              << " is prime:\n";

    if (candidate < 2) {
        std::cout << "  " << candidate << " < 2, so it is not prime.\n";
        return false;
    }

    if (candidate == 2) {
        std::cout << "  2 is prime.\n";
        return true;
    }

    std::cout << "  " << candidate << " mod 2 = " << candidate % 2 << ".\n";
    if (candidate % 2 == 0) {
        std::cout << "  It is divisible by 2, so it is not prime.\n";
        return false;
    }

    for (Integer divisor = 3; divisor <= candidate / divisor; divisor += 2) {
        const Integer remainder = candidate % divisor;
        std::cout << "  " << candidate << " mod " << divisor << " = "
                  << remainder << ".\n";
        if (remainder == 0) {
            std::cout << "  It is divisible by " << divisor
                      << ", so it is not prime.\n";
            return false;
        }
    }

    std::cout << "  No divisor not exceeding sqrt(" << candidate
              << ") was found, so it is prime.\n";
    return true;
}

Integer gcd_with_trace(Integer a, Integer b) {
    std::cout << "Euclidean algorithm for gcd(" << a << ", " << b << "):\n";

    while (b != 0) {
        const Integer quotient = a / b;
        const Integer remainder = a % b;
        std::cout << "  " << a << " = " << b << " * " << quotient
                  << " + " << remainder << "\n";
        a = b;
        b = remainder;
    }

    std::cout << "  The last nonzero remainder is " << a << ".\n";
    return a;
}

BezoutResult extended_gcd_with_trace(SignedInteger a, SignedInteger b) {
    SignedInteger old_remainder = a;
    SignedInteger remainder = b;
    SignedInteger old_a_coefficient = 1;
    SignedInteger a_coefficient = 0;
    SignedInteger old_b_coefficient = 0;
    SignedInteger b_coefficient = 1;

    std::cout << "Extended Euclidean algorithm:\n";
    std::cout << "  Each row maintains r = s * " << a << " + t * " << b
              << ".\n";
    std::cout << "  " << std::setw(12) << "r" << std::setw(12) << "s"
              << std::setw(12) << "t" << '\n';
    std::cout << "  " << std::setw(12) << old_remainder
              << std::setw(12) << old_a_coefficient
              << std::setw(12) << old_b_coefficient << '\n';
    std::cout << "  " << std::setw(12) << remainder
              << std::setw(12) << a_coefficient
              << std::setw(12) << b_coefficient << '\n';

    while (remainder != 0) {
        const SignedInteger quotient = old_remainder / remainder;
        const SignedInteger next_remainder = old_remainder - quotient * remainder;
        const SignedInteger next_a_coefficient =
            old_a_coefficient - quotient * a_coefficient;
        const SignedInteger next_b_coefficient =
            old_b_coefficient - quotient * b_coefficient;

        std::cout << "  q = " << quotient << ": " << old_remainder << " = "
                  << remainder << " * " << quotient << " + "
                  << next_remainder << '\n';

        old_remainder = remainder;
        remainder = next_remainder;
        old_a_coefficient = a_coefficient;
        a_coefficient = next_a_coefficient;
        old_b_coefficient = b_coefficient;
        b_coefficient = next_b_coefficient;

        std::cout << "  " << std::setw(12) << old_remainder
                  << std::setw(12) << old_a_coefficient
                  << std::setw(12) << old_b_coefficient << '\n';
    }

    return {old_remainder, old_a_coefficient, old_b_coefficient};
}

Integer add_mod(Integer a, Integer b, Integer modulus) {
    // The inputs are reduced first. This form avoids overflow in a + b.
    a %= modulus;
    b %= modulus;
    return a >= modulus - b ? a - (modulus - b) : a + b;
}

Integer multiply_mod(Integer a, Integer b, Integer modulus) {
    Integer result = 0;
    a %= modulus;

    while (b != 0) {
        if ((b & 1U) != 0) {
            result = add_mod(result, a, modulus);
        }
        b >>= 1U;
        if (b != 0) {
            a = add_mod(a, a, modulus);
        }
    }

    return result;
}

Integer modular_power_with_trace(Integer base,
                                 Integer exponent,
                                 Integer modulus,
                                 const std::string& operation) {
    Integer result = 1 % modulus;
    base %= modulus;
    Integer remaining_exponent = exponent;
    unsigned int round = 0;

    std::cout << operation << " by right-to-left binary exponentiation:\n";
    std::cout << "  Compute base^exponent mod modulus = " << base << '^'
              << exponent << " mod " << modulus << ".\n";

    while (remaining_exponent != 0) {
        const bool current_bit_is_one = (remaining_exponent & 1U) != 0;
        std::cout << "  Round " << round << ": exponent = "
                  << remaining_exponent << ", bit = "
                  << (current_bit_is_one ? 1 : 0) << ", result = " << result
                  << ", base = " << base << ".\n";

        if (current_bit_is_one) {
            const Integer previous_result = result;
            result = multiply_mod(result, base, modulus);
            std::cout << "    bit 1: result = (" << previous_result << " * "
                      << base << ") mod " << modulus << " = " << result
                      << ".\n";
        } else {
            std::cout << "    bit 0: result is unchanged.\n";
        }

        remaining_exponent >>= 1U;
        if (remaining_exponent != 0) {
            const Integer previous_base = base;
            base = multiply_mod(base, base, modulus);
            std::cout << "    square: base = (" << previous_base << " * "
                      << previous_base << ") mod " << modulus << " = "
                      << base << ".\n";
        }
        ++round;
    }

    std::cout << "  Result: " << result << ".\n";
    return result;
}

void print_usage(const char* program_name) {
    std::cout << "Usage: " << program_name << " [p q e message]\n"
              << "With no arguments, the program uses p=11, q=17, e=7, "
                 "and message=8.\n";
}

}  // namespace

int main(int argc, char* argv[]) {
    try {
        if (argc == 2 && std::string{argv[1]} == "--help") {
            print_usage(argv[0]);
            return 0;
        }

        if (argc != 1 && argc != 5) {
            print_usage(argv[0]);
            return 1;
        }

        Integer p = 11;
        Integer q = 17;
        Integer public_exponent = 7;
        Integer message = 8;

        if (argc == 5) {
            p = parse_integer(argv[1], "p");
            q = parse_integer(argv[2], "q");
            public_exponent = parse_integer(argv[3], "e");
            message = parse_integer(argv[4], "message");
        }

        std::cout << "Toy RSA: a step-by-step arithmetic demonstration\n"
                  << "WARNING: small primes and textbook RSA are insecure.\n\n";
        std::cout << "Input parameters: p=" << p << ", q=" << q
                  << ", e=" << public_exponent << ", message=" << message
                  << ".\n\n";

        if (p > kLargestInputPrime || q > kLargestInputPrime) {
            throw std::invalid_argument(
                "this demonstration limits p and q to 1,000,000");
        }

        std::cout << "Step 1 - Validate the prime inputs\n";
        const bool p_is_prime = is_prime_with_trace(p, "p");
        const bool q_is_prime = is_prime_with_trace(q, "q");
        if (!p_is_prime || !q_is_prime) {
            throw std::invalid_argument("both p and q must be prime");
        }
        if (p == q) {
            throw std::invalid_argument("p and q must be distinct primes");
        }

        if (p > std::numeric_limits<Integer>::max() / q) {
            throw std::overflow_error("p * q does not fit in the integer type");
        }

        std::cout << "\nStep 2 - Compute the modulus and its totient\n";
        const Integer modulus = p * q;
        const Integer totient = (p - 1) * (q - 1);
        std::cout << "  n = p * q = " << p << " * " << q << " = "
                  << modulus << ".\n";
        std::cout << "  phi(n) = (p - 1)(q - 1) = " << (p - 1) << " * "
                  << (q - 1) << " = " << totient << ".\n";

        if (public_exponent <= 1 || public_exponent >= totient) {
            throw std::invalid_argument("e must satisfy 1 < e < phi(n)");
        }

        std::cout << "\nStep 3 - Check that e is coprime to phi(n)\n";
        const Integer common_divisor =
            gcd_with_trace(totient, public_exponent);
        if (common_divisor != 1) {
            throw std::invalid_argument("e has no inverse modulo phi(n)");
        }
        std::cout << "  Therefore gcd(e, phi(n)) = 1.\n";

        std::cout << "\nStep 4 - Compute the private exponent d\n";
        const auto bezout = extended_gcd_with_trace(
            static_cast<SignedInteger>(totient),
            static_cast<SignedInteger>(public_exponent));
        std::cout << "  Bezout identity: " << bezout.gcd << " = ("
                  << bezout.coefficient_a << ") * " << totient << " + ("
                  << bezout.coefficient_b << ") * " << public_exponent
                  << ".\n";

        const SignedInteger signed_totient =
            static_cast<SignedInteger>(totient);
        const SignedInteger normalized_inverse =
            (bezout.coefficient_b % signed_totient + signed_totient) %
            signed_totient;
        const Integer private_exponent =
            static_cast<Integer>(normalized_inverse);
        std::cout << "  The coefficient of e is its inverse modulo phi(n).\n";
        std::cout << "  d = " << bezout.coefficient_b << " mod " << totient
                  << " = " << private_exponent << ".\n";
        std::cout << "  Check: (e * d) mod phi(n) = (" << public_exponent
                  << " * " << private_exponent << ") mod " << totient
                  << " = "
                  << multiply_mod(public_exponent, private_exponent, totient)
                  << ".\n";

        if (message >= modulus) {
            throw std::invalid_argument("message must satisfy 0 <= message < n");
        }

        std::cout << "\nStep 5 - State the keys\n";
        std::cout << "  Public key:  (n, e) = (" << modulus << ", "
                  << public_exponent << ").\n";
        std::cout << "  Private key: (n, d) = (" << modulus << ", "
                  << private_exponent << ").\n";

        std::cout << "\nStep 6 - Encrypt the message\n";
        const Integer ciphertext = modular_power_with_trace(
            message, public_exponent, modulus, "Encryption");
        std::cout << "  c = message^e mod n = " << ciphertext << ".\n";

        std::cout << "\nStep 7 - Decrypt the ciphertext\n";
        const Integer recovered_message = modular_power_with_trace(
            ciphertext, private_exponent, modulus, "Decryption");
        std::cout << "  recovered = c^d mod n = " << recovered_message
                  << ".\n";

        std::cout << "\nStep 8 - Verify correctness\n";
        std::cout << "  Original message:  " << message << '\n';
        std::cout << "  Recovered message: " << recovered_message << '\n';
        if (recovered_message != message) {
            std::cout << "  FAILURE: the values are different.\n";
            return 2;
        }

        std::cout << "  SUCCESS: decryption recovered the original message.\n";
        return 0;
    } catch (const std::exception& error) {
        std::cerr << "Error: " << error.what() << '\n';
        return 1;
    }
}
