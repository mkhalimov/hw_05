#include <gtest/gtest.h>
#include <sstream>
#include "../src/RLE.hpp"

// Demonstrate some basic assertions.
TEST(RLETest, FirstEncodeTest) {
    std::stringstream input("ABBBCCCCCDDDDEEEE");
    std::stringstream output;
    
    RLE<8> rle_encoder(input, output);
    rle_encoder.Process();

    EXPECT_EQ(output.str(), "11A000000011B000000101C000000100D000000100E"); // E
}
TEST(RLETest, SecondEncodeTest) {
    std::stringstream input("!!!!!****?????..!!)(");
    std::stringstream output;
    
    RLE<8> rle_encoder(input, output);
    rle_encoder.Process();

    EXPECT_EQ(output.str(), "000000101!000000100*000000101?000000010.000000010!11)11(");
    
}
TEST(RLETest, ThirdEncodeTest) {
    std::stringstream input("A23FFFFFF444AAAAA");
    std::stringstream output;
    
    RLE<8> rle_encoder(input, output);
    rle_encoder.Process();

    EXPECT_EQ(output.str(), "11A112113000000110F0000000114000000101A"); // A
    
}
TEST(RLETest, DecodeTest) {
    std::stringstream input("11A000000011B000000101C000000100D000000100E");
    std::stringstream output;
    
    RLEDecoder<8> rle_decoder(input, output);
    rle_decoder.Process();

    EXPECT_EQ(output.str(), "ABBBCCCCCDDDDEEEE");
    
}
TEST(RLETest, SecondDecodeTest) {
    std::stringstream input("000000101!000000100*000000101?000000010.000000010!11)11(");
    std::stringstream output;
    
    RLEDecoder<8> rle_decoder(input, output);
    rle_decoder.Process();

    EXPECT_EQ(output.str(), "!!!!!****?????..!!)(");
    
}
TEST(RLETest, ThirdDecodeTest) {
    std::stringstream input("11S11A11O11K11F11M11K11O11S11A11M11F11K11L11S11A11M11F11K11L11S11A11F11M11K11A11S11M11K11L11S11A11M11F11K11S11M11G11L11M11V");
    std::stringstream output;
    
    RLEDecoder<8> rle_decoder(input, output);
    rle_decoder.Process();

    EXPECT_EQ(output.str(), "SAOKFMKOSAMFKLSAMFKLSAFMKASMKLSAMFKSMGLMV");
    
}



int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
