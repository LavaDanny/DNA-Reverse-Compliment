#include "dna.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>


DNA::DNA(){

}

DNA::DNA(std::string header, std::string sequence){
  hdr = header;
  seq = sequence;
  if (header[0] != '>'){
    throw std::runtime_error();
  }
  for (int i = 0; i < (int) sequence.length(); i++){
    if (sequence[i] != 'T' && 'C' && 'A' && 'G' && 'N') {
    throw std::runtime_error();
  }
}
std::string DNA::getSequence(){
  return seq;
}
std::string DNA::getHeader(){
  return hdr;
}

DNA::revcomp(){
}

size_t DNA::find(std::string query, size_t start){
}

DNA::DNA(std::ifstream &infile){
}

std::string DNA::toFasta(int columns=80){
}

bool operator==(DNA::DNA d1, DNA::DNA d2){
  std::string s = d1.getSequence();
  std::string t = d2.getSequence();
}
