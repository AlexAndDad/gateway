#include "minecraft/security/cipher_context.hpp"
#include "polyfill/explain.hpp"
#include <catch2/catch.hpp>

TEST_CASE("minecraft::security::cipher_context")
{
    using namespace minecraft;

    SECTION("round trip")
    {
        std::string const original = R"frankie(Welcome to the pleasure dome
Welcome to the pleasure dome

Who-ha! Who-ha! Who-ha! Who-ha!
Who-ha! Who-ha! Who-ha! Who-ha!

Ha!

The animals are winding me up
The jungle call, the jungle call

Who-ha! Who-ha! Who-ha! Who-ha!

In Xanadu did Kublai Khan a pleasuredome erect
Moving on, keep moving on, yeah

Moving at one million miles an hour
Using my power, I sell it by the hour
I have it so I market it
You really can't afford it, yeah, really can't afford it

Shooting stars never stop even when they reach the top
Shooting stars never stop even when they reach the top
There goes a supernova. What a pushover, yeah
There goes a supernova. What a pushover

We're a long way from home
Welcome to the Pleasuredome
On our way home
Going home where lovers roam
Long way from home
Welcome to the Pleasuredome

Moving on, keep moving on

I will give you diamonds by the shower
Love your body even when it's old
Do it just as only I can do it
And never ever doing what I'm told

Shooting stars never stop even when they reach the top
Shooting stars never stop even when they reach the top
There goes a supernova. What a pushover, yeah
There goes a supernova. What a pushover

We're a long way from home
Welcome to the pleasuredome
On our way home
Going home where lovers roam
Long way from home
Welcome to the pleasuredome

Keep moving on
Got to reach the top, don't stop
Pay love and life, oh my
Keep moving on, yeah

Shooting stars never stop
Shooting stars never stop

Shooting stars never stop even when they reach the top
There goes a supernova. What a pushover
Shooting stars never stop even when they reach the top
There goes a supernova. What a pushover, yeah
There goes a supernova

Who-ha! Who-ha!
Welcome to the pleasuredome
Who-ha! Who-ha!
Going home where lovers roam
Welcome to the pleasuredome

Erect!

Who-ha! Who-ha!

The war is won)frankie";


        auto iv_and_key = std::array< std::uint8_t, 16 >({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 });

        auto encryption_cipher =
            minecraft::security::encryption_context(minecraft::net::buffer(iv_and_key), minecraft::net::buffer(iv_and_key));

        auto plaintext = original;
        std::string ciphertext;

        try
        {
            encryption_cipher.update(net::buffer(plaintext),
                                     minecraft::net::dynamic_buffer(ciphertext));
        }
        catch(...)
        {
            INFO("" << polyfill::explain());
            FAIL();
        }
        CHECK(ciphertext.size() == 1845);
        encryption_cipher.finalise(minecraft::net::dynamic_buffer(ciphertext));
        CHECK(ciphertext.size() == 1845);

        auto decryption_cipher =
            minecraft::security::decryption_context(minecraft::net::buffer(iv_and_key), minecraft::net::buffer(iv_and_key));
        try
        {
            plaintext.clear();
            decryption_cipher.update(minecraft::net::buffer(ciphertext),
                                     minecraft::net::dynamic_buffer(plaintext));
        }
        catch(...)
        {
            INFO("" << polyfill::explain());
            FAIL();
        }
        CHECK(plaintext.size() == 1845);
        decryption_cipher.finalise(minecraft::net::dynamic_buffer(plaintext));
        CHECK(plaintext.size() == 1845);

        CHECK(plaintext == original);
    }
}
