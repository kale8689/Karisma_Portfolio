// to start code use g++ -std=c++17 dnaProjectFunctions.cpp and ./a.out
#include <iostream>
#include <string>
using namespace std;

// Question One
// Check if DNA nucleotide bases are a valid base
bool isValidBase(char base){
    // only A,G,T,C valid nucleotide values
    if(base == 'A' || base == 'G' || base == 'T' || base == 'C'){
        return true;
    }
    else{
        return false;
    }
    // 0 is false, 1 is true
}

// Question Two
// Check if DNA strand contains only valid bases
bool isValidStrand(string strand){
    // strand is empty false
    if(strand.empty()){
        return false;
    }
    // For a string validating all letters are valid nucleotides
    for(int i = 0; i < strand.length(); i++){
        // using isValidBase function to validate each character
        isValidBase(strand[i]);
        // if its not valid then it returns false
        if(!isValidBase(strand[i])){
                return false;
            }
        }
    return true;
}

// Question Three
// Calculate the similarity between two sequences of the same length
double strandSimilarity(string strand1, string strand2){
    // declare variables
    double count = 0.0, similarity = 0.0;
    // if the lengths do not equal then returns 0
    if(strand1.length() != strand2.length()){
        return 0;
    }
    // For every character that is same in both strands, count++
    for(int i = 0; i < strand1.length(); i++){
        if(strand1[i] == strand2[i]){
            count++;
        }
    }
    // calculating similarity and returning it
    similarity = count / strand1.length();
    return similarity;
}

// Question Four
// Calculate the best similarity between two sequences of either equal or unequal length
int bestStrandMatch(string input_strand, string target_strand){
    // defining variables
    double highestSimilarity = 0.0, similarity = 0.0;
    int bestIndex = 0;
    string shortinput = "";
    // if input smaller than target then score=0.0 return -1
    if(input_strand.length() < target_strand.length()){
        cout << "Best similarity score: 0.0" << endl;
        return -1;
    }
    // comparing target to input to find highest similarity value and best index
    for(int i = 0; i < input_strand.length(); i++){
        //since input is always bigger, we compare the smallinput= target length, to it
        shortinput = input_strand.substr(i, target_strand.length());
        // use previous function to find similarity from each index
        similarity = strandSimilarity(shortinput, target_strand);
        // continuely updates until similarity is the biggest
        if(similarity > highestSimilarity){
            highestSimilarity = similarity;
            bestIndex = i;
        }
    }
    // tells user results
    cout << "Best similarity score: " << highestSimilarity << endl;
    return bestIndex;
}

// Question Five
// Identify mutations
void identifyMutations(string input_strand, string target_strand){
    // declare variables
    string longest_strand, shorter_strand;
    int bestIndex = 0;
    bool foundMutation = false;

    // Determine which strand is longer
    if(input_strand.length() >= target_strand.length()){
        longest_strand = input_strand;
        shorter_strand = target_strand;
    }
    else{
        longest_strand = target_strand;
        shorter_strand = input_strand;
    }
    // using old function for similarity and alignment outputs.
    bestIndex = bestStrandMatch(longest_strand, shorter_strand);
    cout << "Best alignment index: " << bestIndex << endl;

    // using original input and target strand to find sub/in/del
    // I want to pad by putting 0 in empty spaces in target and input
    // defining new variables to pad
    string padInput = "", padTarget = "";
   int totalStrandLength = longest_strand.length();
// Case 1: bestindex == 0 so pads target and input strand the same.
if(bestIndex == 0){
    // in a for loop where if i less then target_strand.length() it adds the target_strand[i]
    // to a new string called padTarget
    // however if its more it means there is empty space so it adds '0' to fill gap
    for(int i = 0; i < totalStrandLength; i++){
        // pad target strand.
        if(i < target_strand.length()){
            padTarget += target_strand[i];}
        else{
            padTarget += "0";}
        // pad input strand
        if (i < input_strand.length()){
            padInput += input_strand[i];} 
        else{
            padInput += "0";}
    }
}
// Case 2: where the target strand is the longest strand and the bestIndex > 0
if(bestIndex > 0 && longest_strand == target_strand){
  for (int i = 0; i < totalStrandLength; i++) {
        // Target strand (no shifting bc longest)
        if (i < target_strand.length()) {
            padTarget += target_strand[i];
        } else {
            padTarget += "0";}
        // Input strand (shifted by bestIndex)
        int inputIndex = i - bestIndex;
        if (inputIndex >= 0 && inputIndex < input_strand.length()) {
            padInput += input_strand[inputIndex];
        } else {
            padInput += "0";}
    }  
}
// Case 3: where the input strand is the longest strand and the bestIndex > 0
if(bestIndex > 0 && longest_strand == input_strand){
    for (int i = 0; i < totalStrandLength; i++){
        // input strand (longest no shifting)
        if (i < input_strand.length()) {
            padInput += input_strand[i];
        } else {
            padInput += "0";}
        // Target strand (shifted by bestIndex)
        int targetIndex = i - bestIndex;
        if (targetIndex >= 0 && targetIndex < target_strand.length()) {
            padTarget += target_strand[targetIndex];
        } else {
            padTarget += "0";}
    }  
}
// finally loops through new strings, padTarget and padInput to find mutations
for(int j = 0; j < totalStrandLength; j++){
        // insertion where it finds an 0 in padInput
        if(padInput[j] == '0'){
            cout << "Insertion at position " << j + 1 << ": " << padTarget[j]
                 << " is inserted in target strand" << endl;
            // a bool to say whether a mutation is found
            foundMutation = true;
        }
        // deletion where it finds an 0 in padTarget
        if(padTarget[j] == '0'){
             cout << "Deletion at position " << j + 1 << ": " << padInput[j]
                 << " is deleted in target strand" << endl;
            foundMutation = true;
        }
        // substitution where the two characters differ from each other
        else if(padInput[j] != padTarget[j]){
            cout << "Substitution at position " << j + 1 << ": " << input_strand[j] << " -> " << target_strand[j] << endl;
        }
        foundMutation = true;
    }
    // if the foundMutation is not true then no mutations was found. 
    if(!foundMutation){
        cout << "No mutations found." << endl;
    }
}

// Question Six
// Transcribe DNA to RNA
void transcribeDNAtoRNA(string strand){
    // loops through each index and changes T to U
    for(int i = 0; i < strand.length(); i++){
        if(strand[i] == 'T'){
            strand[i] = 'U';
        }
    }
    // outputs result
    cout << strand << endl;
}

// Question Seven
// Find the reverse complement of a DNA sequence
void reverseComplement(string strand){
    string complement = "";
    // loops through every index but backwards and inputs char into new complement string
    for(int i = strand.length() - 1; i >= 0; i--){
        // changes A to T
        if(strand[i] == 'A'){
            complement += 'T';
        }
        // changes T to A
        else if(strand[i] == 'T'){
            complement += 'A';
        }
        // changes C to G
        else if(strand[i] == 'C'){
            complement += 'G';
        }
        // changes G to C
        else if(strand[i] == 'G'){
            complement += 'C';
        }
    }
    // outputs
    cout << complement << endl;  
}

// Question Eight
// Extract coding frames
void getCodingFrames(string strand){
    // declaring variables and all the stop and start codons
    string frame = "";
    string startCodon = "ATG";
    string stopCodon1 = "TAA";
    string stopCodon2 = "TAG";
    string stopCodon3 = "TGA";
    string codon = "";
    bool readingFrame = false;
// first finds start codon
    for(int i = 0; i <= strand.length() - 3; i++){
        // inputs ATG into frame string first if there is the startCodon
        if(strand.substr(i, 3) == startCodon){
            frame = "ATG";
            // after finding codon, inputs codons after, reads three at a time in loop
            for(int j = i + 3; j <= strand.length() - 3; j += 3){
                // adds in three at a time into the frame string
                codon = strand.substr(j, 3);
                frame += codon;
                // finds stop codon then stops the sequence
                if(codon == stopCodon1 || codon == stopCodon2 || codon == stopCodon3) {
                    cout << frame << endl;
                    // if there is a start & stop codon then its true that there is a readingFrame
                    readingFrame = true;
                    break;
                }
            }
        }
    }
    // no start codon / stop codon error
    if(!readingFrame) {
        cout << "No reading frames found." << endl;
    }
}

// Question Nine THE MENU
// main menu that will ask you what you want to do with your data strand
int main() {
    // declaring variables
    int input = 0;
    double similarity = 0.0;
    string strand1, strand2, DNAtoRNA, DNAtoRNAresult, DNAcomplement, DNAframes;
    string inputStrand, outputStrand, strand = "", complement = "";
    // string mainMenu from canvas annocements
    string mainMenu = "--- DNA Analysis Menu ---\n"
                       "1. Calculate the similarity between two sequences of the same length\n"
                       "2. Calculate the best similarity between two sequences of either equal or unequal length\n"
                       "3. Identify mutations\n"
                       "4. Transcribe DNA to RNA\n"
                       "5. Find the reverse complement of a DNA sequence\n"
                       "6. Extract coding frames\n"
                       "7. Exit\n"
                       "Please enter your choice (1 - 7): ";
    // starts with a do while loop to continually ask for correct inputs
    do{
        cout << mainMenu << endl;
        cin >> input;
        // switch statements for 1-7 questions
        switch(input){
            // finds similarity between two strands.
            case 1:
                // do while loop to continually ask for correct inputs for strand1
                do{
                    cout << "Enter the first DNA sequence:" << endl;
                    cin >> strand1;
                    if(!isValidStrand(strand1)){
                        cout << "Invalid input. Please enter a valid sequence." << endl;
                    }
                }while(!isValidStrand(strand1));
                // do while loop to continually ask for correct inputs for strand2
                do{
                    cout << "Enter the second DNA sequence:" << endl;
                    cin >> strand2;
                    if(!isValidStrand(strand2)){
                        cout << "Invalid input. Please enter a valid sequence." << endl;
                    }
                }while(!isValidStrand(strand2));
                // checking if both strands are some length
                if(strand1.length() != strand2.length()){
                    cout << "Error: Input strands must be of the same length." << endl;
                    break;
                }
                // if passes all checks above, performs function and outputs
                similarity = strandSimilarity(strand1, strand2);
                cout << "Similarity score: " << similarity << endl;
                break;
            // finds best strand match
            case 2:
                // do whiles until valid inputs for DNA sequences output and input strands
                do{
                    cout << "Enter the first DNA sequence:" << endl;
                    cin >> inputStrand;
                    if(!isValidStrand(inputStrand)){
                        cout << "Invalid input. Please enter a valid sequence." << endl;
                    }
                }while(!isValidStrand(inputStrand));
                do{
                    cout << "Enter the second DNA sequence:" << endl;
                    cin >> outputStrand;
                    if(!isValidStrand(outputStrand)){
                        cout << "Invalid input. Please enter a valid sequence." << endl;
                    }
                }while(!isValidStrand(outputStrand));
                // once passes checks then bestStrandMatch function preforms
                bestStrandMatch(inputStrand, outputStrand);
                break;
            // identify mutations
            case 3:
                cout << "Enter the first DNA sequence:" << endl;
                cin >> inputStrand;
                cout << "Enter the second DNA sequence:" << endl;
                cin >> outputStrand;
                identifyMutations(inputStrand, outputStrand);
                break;
            // transcribes DNA to RNA
            case 4:
                // do while loop for correct valid strand for DNAtoRNA
                do{
                    cout << "Enter the DNA sequence to be transcribed: " << endl;
                    cin >> DNAtoRNA;
                    if(!isValidStrand(DNAtoRNA)){
                        cout << "Invalid input. Please enter a valid sequence." << endl;
                    }
                }while(!isValidStrand(DNAtoRNA));
                // passes check then preforms function.
                cout << "The transcribed DNA is: ";
                transcribeDNAtoRNA(DNAtoRNA);
                break;
            // finds the reverse complement
            case 5:
                // do while loop to for valid sequences
                do{
                    cout << "Enter the DNA sequence: " << endl;
                    cin >> DNAcomplement;
                    if(!isValidStrand(DNAcomplement)){
                        cout << "Invalid input. Please enter a valid sequence." << endl;
                    }
                }while(!isValidStrand(DNAcomplement));
                // once pass checks then function preforms
                cout << "The reverse complement is: ";
                reverseComplement(DNAcomplement);
                break;
            // seperate the frames by specific codons
            case 6:
                // do while loop for valid frames
                do{
                    cout << "Enter the DNA sequence: " << endl;
                    cin >> DNAframes;
                    if(!isValidStrand(DNAframes)){
                        cout << "Invalid input. Please enter a valid sequence." << endl;
                    }
                }while(!isValidStrand(DNAframes));
                // function preforms and prints
                getCodingFrames(DNAframes);
                break;
            // exiting program
            case 7:
                cout << "Exiting program." << endl;
                return 0;
            // if they do not pick valid option 1-7
            default:
                cout << "Invalid input. Please select a valid option." << endl;
        }
    } while (input <= 8);

} 
