#include "dna.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
//Default Constructor

DNA::DNA(){
   hdr = "";
   seq = "";
}
//creating DNA header and sequence strings
DNA::DNA(std::string header, std::string sequence) {
   hdr = header;
   seq = sequence;
  if (header[0] != '>')  {
    throw std::runtime_error("Invalid header format.");
  }
  else {
   hdr = header;
  }
  for (int i = 0; i < (int) sequence.length(); i++){
    if (sequence[i] != 'A' && 'T' && 'C' && 'G' && 'N') {
    throw std::runtime_error("Invalid sequence format.");
    }
  }
   seq = sequence;
}
  //getter method for sequence
std::string DNA::getSequence(){
  return seq;
}
  //getter method for header
std::string DNA::getHeader(){
  return hdr;
}
  //reverse complementing a sequence string
DNA DNA::revcomp(){
  std::string revcomp = "";
  for (int i = (int)seq.length() - 1; i >= 0; i--)
    if (seq[i] == 'A'){
      revcomp += 'T';
      }
    else if (seq[i] == 'T'){
      revcomp += 'A';
      }
    else if (seq[i] == 'C'){
      revcomp += 'G';
      }
    else if (seq[i] == 'G'){
      revcomp += 'C';
    }
    else if (seq[i] == 'N'){
      revcomp += 'N';
    }
DNA::DNA rc = DNA::DNA(hdr, revcomp);
return rc;
}
//unimplimented methods

size_t DNA::find(std::string query, size_t start){
  size_t d = seq.find(query, start);
  DNA::DNA dna = DNA::DNA(hdr, query);
  DNA::DNA rev = dna.revcomp();
  std::string rc = rev.getSequence();
  size_t r = rc.find(query, start);
  if (r > d && d != std::string::npos){
    return d;
  }
  else
  {
    return r;
  }
}

DNA::DNA(std::ifstream &infile){
  std::vector<std::string>sq;
  std::string file;
    std::string line;
    while (getline(infile, line)) {
      if (line.at(0) != '>'){
        throw std::runtime_error("Invalid header format.");
      }
      else sq.push_back(line);
  }
  for (int i = sq.size() - 1; i>=0; i--){
    if (sq[i] == sq[0]){
      file += sq[i];
      file += '\n';
    }
    else {
      std::string sequence = sq[i];
      for (int i = 0; i < (int) sequence.length(); i++) {
        if (sequence[i] != 'A' && 'T' && 'C' && 'G' && 'N') {
          throw std::runtime_error("Invalid sequence format.");
        }
        else {
          file += sequence[i];
        }
      }
    }
  }
}
std::string DNA::toFasta(int columns){
  std::string f = "";
  for (int i = 0; i < (int) seq.length(); i++){
    if (seq[i] == columns){
      f[i] += '\n';
    }
    else {
      f += seq[i];
    }
  }
  return f;
}
bool operator==(DNA::DNA d1, DNA::DNA d2){
  std::string s = d1.getSequence();
  std::string t = d2.getSequence();
  return s == t;
}
