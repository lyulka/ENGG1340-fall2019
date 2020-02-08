//
//  Assignment 2 Task 3 template
//  Copyright © 2019 HKU COMP2113. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int MAX_NUM_STOPWORDS = 100;

// a structure for storing a stop_words and its corresponding removal count
struct Stop_word
{
  string word;  // stop word
  int count;    // removal count
};

///////// DO NOT MODIFY ANYTHING ABOVE THIS LINE /////////

// IMPORTANT:  Do NOT change any of the function headers
//             It means that you will need to use the function headers as is


// You may implement additional functions here



//
// ReadStopWordFromFile:  read stop words from a file and
//                store them in an array of struct Stop_word
//                (also initialize removal count of each stop word to zero)
// input:   stop_word_filename - name of the file containing stop words
// output:  words[] - an array to store the stop words read from input file
//          num_words - number of stop words read from file
void ReadStopWordFromFile(string stop_word_filename, Stop_word words[], int &num_words)
{
  string tempWord = ""; // this string is used to store individual lines from the stopwords file

  // wordFile is the stream associated with the words file
  ifstream wordFile;
  wordFile.open(stop_word_filename);

  // Looping through the file
  int i = -1;
  while (getline(wordFile, tempWord)) {
    i++;
    words[i].word = tempWord;
  }

  if (i >= 0) 
    num_words = i + 1;

  wordFile.close();
}

//
// WriteStopWordCountToFile:  write stop words and removal counts to a file
//
// input: wordcount_filename - name of the file to write to
//        words[] - an array storing the stop words and removal counts
//        num_words - number of stop words in words[]
//
void WriteStopWordCountToFile(string wordcount_filename, Stop_word words[], int num_words)
{
  // wordCountFile is the stream associated with the wordcounts file
  ofstream wordCountFile;
  wordCountFile.open(wordcount_filename);

  // Looping through the file
  for (int i = 0; i < num_words; i++)
    wordCountFile << words[i].word << " " << words[i].count << endl;

  wordCountFile.close();
}



//
// RemoveWordFromLine: to delete all occurrences of a word from a line of text
//
// input: line - a string of text to be processed
//        word - a word whose occurrences are to be removed from line
// output: an integer for the number of times the word is being removed
//
int RemoveWordFromLine(string &line, string word)
{
  int wordLength = word.length();
  int lineLength = line.length();
  int startIndex = line.find(word);
  int numberFound = 0;

  string replacementWhitespace = "";

  int leadingSpaceIndex, trailingSpaceIndex;

  // loop while instances of the word can still be found
  while (startIndex != string::npos) {
    // two indices used to check if the word stands on its own
    // as opposed to being a part of a larger word
    leadingSpaceIndex = startIndex - 1;
    trailingSpaceIndex = startIndex + wordLength;

    if ((line[leadingSpaceIndex] == ' ' || leadingSpaceIndex == -1)
     && (line[trailingSpaceIndex] == ' ' || trailingSpaceIndex == lineLength))
     {
      line.replace(startIndex, wordLength, replacementWhitespace);
      numberFound++;
     } 
    startIndex = line.find(word, startIndex + 1);
     

  }
  return numberFound;
}

//
// RemoveAllStopwordsFromLine: deleting all occurrences of all stop words from
//      a given line of text
//      this function calls RemoveWordFromLine() to remove all occurrences of
//      a stop word,
//
// input:  line - a string of text to process
//         words[] - an array of stop words to remove from line
//         num_words - number of stop words stored in words[]
// output: line - with all stop words removed
// return: an integer for number of words removed from line
//
int RemoveAllStopwordsFromLine(string &line, Stop_word words[], int num_words)
{
  int totalRemoved = 0;
  for (int i = 0; i < num_words; i++) {
    words[i].count = RemoveWordFromLine(line, words[i].word);
    totalRemoved += words[i].count;
  }

  return totalRemoved;
}


int main() {

  Stop_word stopwords[MAX_NUM_STOPWORDS];     // an array of struct Stop_word

  string wordsFileName; 
  int num_words;
  string textFileName;


  // read in two filenames from user input
  cin >> wordsFileName >> textFileName;

  // prepare file name for stopwords_count.txt
  string ext = ".txt";
  string wordsFileNamePrepared = wordsFileName.substr(0, wordsFileName.size() - ext.size());


  string wordCountFilename = wordsFileNamePrepared + "_count.txt";

  // open text file
  ifstream textFile;
  textFile.open(textFileName);

  // try opening stopwords file
  ifstream stopWordsFile;
  stopWordsFile.open(wordsFileName);

  // check if we failed to open any of the input files
  bool success = true;
  if (textFile.fail()) {
    cout << "Failed to open " << textFileName << endl;
    success = false;
  }

  if (stopWordsFile.fail()) {
    cout << "Failed to open " << wordsFileName << endl;
    success = false;
  }

  if (!success) {
    return -1;
  }

  stopWordsFile.close();


  // read stop words from stopword file and
  // store them in an array of struct Stop_word
  ReadStopWordFromFile(wordsFileName, stopwords, num_words);


  // open cleaned text file
  ofstream cleanedTextFile;
  cleanedTextFile.open("cleaned_"+ textFileName);



  // read in each line from text file, remove stop words,
  // and write to output cleaned text file
  string processLine;
  int totalRemoved = 0;
  while (getline(textFile, processLine)) {
    totalRemoved += RemoveAllStopwordsFromLine(processLine, stopwords, num_words);
    cleanedTextFile << processLine << endl;
  }



  // close text file and cleaned text file
  textFile.close();
  cleanedTextFile.close();


  // write removal count of stop words to files
  WriteStopWordCountToFile(wordCountFilename, stopwords, num_words);


  // output to screen total number of words removed
  cout << "Number of stop words removed: " << totalRemoved;



  return 0;
}
