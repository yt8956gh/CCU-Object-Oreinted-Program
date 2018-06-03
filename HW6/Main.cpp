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

    cout << t2.decode("01010110100010001100000111000111011100001110111100100010011110111010011010110101100111000010001010111010010000101000101010010000011000110")<<endl;

	cout << t2.encode("silly old bear is winnie-the-pooh") << endl;

	cout << t2.decode("1001110000100010101110100100001010001010100100000110001101011101001101010101101000100011000001110001110111000011101111001000100111") << endl;


	HuffmanTree t3("This summer's World Cup in Russia could well be the last one staged by just one country for some time, as financial and political considerations play an ever-increasing role in choosing hosts.");

	cout<<t3.encode("World Cup in Russia")<<endl;
	cout<<t3.decode("110110000111110101011000000111101010001100000000011001000001111001100010010001001101001")<<endl;


	return 0;
}
