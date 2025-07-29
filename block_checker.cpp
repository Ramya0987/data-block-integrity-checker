
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Simulated simple checksum function: sum of ASCII values modulo 256
int computeChecksum(const string& block) {
    int checksum = 0;
    for (char c : block) {
        checksum = (checksum + static_cast<unsigned char>(c)) % 256;
    }
    return checksum;
}

// Read file and break into blocks
vector<string> splitFileIntoBlocks(const string& filename, size_t blockSize) {
    ifstream file(filename, ios::binary);
    vector<string> blocks;
    string block(blockSize, '\0');

    while (file.read(&block[0], blockSize) || file.gcount()) {
        block.resize(file.gcount());
        blocks.push_back(block);
    }
    return blocks;
}

int main() {
    string filename = "sample_data.txt";
    size_t blockSize = 64;

    vector<string> originalBlocks = splitFileIntoBlocks(filename, blockSize);
    vector<int> originalChecksums;

    for (const auto& block : originalBlocks) {
        originalChecksums.push_back(computeChecksum(block));
    }

    // Simulate corruption in 3 blocks
    vector<string> corruptedBlocks = originalBlocks;
    if (corruptedBlocks.size() > 11) corruptedBlocks[5] = "CORRUPTED";
    if (corruptedBlocks.size() > 3)  corruptedBlocks[3] = "INVALID_BLOCK";
    if (corruptedBlocks.size() > 8)  corruptedBlocks[8] = "DAMAGED DATA";

    cout << "Block\tValid\n";
    for (size_t i = 0; i < corruptedBlocks.size(); ++i) {
        int checksum = computeChecksum(corruptedBlocks[i]);
        bool isValid = checksum == originalChecksums[i];
        cout << i << "\t" << (isValid ? "True" : "False") << endl;
    }

    return 0;
}
