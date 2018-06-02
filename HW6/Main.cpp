// Main Program Example for HW6

// You can use this file as your main program, or add more functions if you want.
// Please ***MAKE SURE*** that your class works fine in this main program.
// TA will test your class by this program with additional test data.

#include <iostream>
#include <string>
#include "HuffmanTree.h"

using std::cout;
using std::endl;
using std::string;


int main(){
	// Build a Huffman Tree according to the string
	HuffmanTree t("Abcdaaaabbbbaaaacceee!@&$()#@%*");

	// encode a string
	cout << t.encode("Abcdaaaabbbbaaaacc") << endl;

    cout << t.decode("11001111001110000101010111111111111101010101001001")<<endl;

    // The Hoffman Tree t will be unable to encode this
	// Therefore, please print out error message and return an empty string("") when encounter this.
	cout << t.encode("Abcdaaaeeeabbbbaaaac@@@%%cRRRRR") << endl;

	// decode a string
	cout << t.decode("101011110000111100101111111010111") << endl;

	// The Hoffman Tree t will be unable to decode this
	// Therefore, please print out error message and return an empty string("") when encounter this.
	cout << t.decode("1010111100001111001011111110101111") << endl;

	HuffmanTree t2("winnie-the-poohis a silly old bear");

	cout << t2.encode("winnie-the-pooh is a silly old bear") << endl;

    cout << t2.decode("10101001011101110011111000111000100011110001000011011101100001000101100101001010011000111101110101000101101111010111010101101111100111001")<<endl;

	cout << t2.encode("silly old bear is winnie-the-pooh") << endl;

	cout << t2.decode("01100011110111010100010110111101011101010110111110011100101000101100101010100101110111001111101011000100011110100000110111011000") << endl;


	return 0;
}
