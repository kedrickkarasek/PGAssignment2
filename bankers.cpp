#include <iostream> 
#include <fstream> 
#include <vector> 
#include <string> 
#include <ctype.h> 


void getData(std::vector< std::vector<int> > &all, std::vector< std::vector<int> > &max, std::vector<int> &ava, int &pro, int &res) {
    std::ifstream in; 
    in.open("input.csv");
    if(!in) { 
        std::cerr << "File Could Not Be Loaded" << '\n';
        exit(1);
    }

    char c;
    int i = 0; 
    std::string word; 
    std::vector<int> row;

        while(!in.eof()) { 
            in.get(c); 
            if(!isdigit(c)) {
                if(word != "") { 
                    int num = std::stoi(word); 

                    if(i == 2) { 
                        ava.push_back(num);
                    }
                    
                    row.push_back(num); 
                }

                word = ""; 
            }
            else if(isdigit(c) && c != ' ' && c != ',') { 
                word.push_back(c);
            }

            if(c == '\n' || c == '\t' || c == '\r') { 
                i = 0; 
                row.clear();            
            }
            else if(c == ',') { 
                if(i == 0) {
                    all.push_back(row); 
                }
                else if(i == 1) { 
                    max.push_back(row); 
                }
                row.clear();       
                i++; 
            }
        }

    pro = all.size();
    res = ava.size(); 
}

int main() {
    int pro, res; 

    std::vector< std::vector<int> > all; 
    std::vector< std::vector<int> > max; 
    std::vector<int> ava; 

    getData(all, max, ava, pro, res); 

    std::cout << "\nAllocated Resource Table\n"; 
    for(int i = 0; i < pro; i++) { 
        for(int j = 0; j < res; j++) {
            std::cout << all[i][j] << " ";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
    std::cout << "Maxinum Resource Table\n"; 
    for(int i = 0; i < pro; i++) { 
        for(int j = 0; j < res; j++) {
            std::cout << max[i][j] << " ";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
    std::cout << "List of Available Resources\n"; 
    for(int i = 0; i < res; i++) {
       std::cout << ava[i] << " "; 
    }
    std::cout << "\n\n";

    int fin[pro]; 
    int end[pro]; 
    int nee[pro][res]; 
    int step = 0; 

    for(int i = 0; i < pro; i++) 
        fin[i] = 0;

    for(int i = 0; i < pro; i++) { 
        for(int j = 0; j < res; j++) {
            nee[i][j] = max[i][j] - all[i][j];
        }
    }
    std::cout << "List of Needed Resources\n";
    for(int i = 0; i < pro; i++) { 
        for(int j = 0; j < res; j++) {
            std::cout << nee[i][j] << " ";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
    for(int i = 0; i < pro; i++) {
        for(int j = 0; j < pro; j++) { 
            if(fin[j] == 0) { 
                int boo = 0; 
            
                for(int k = 0; k < res; k++) { 
                    if(nee[j][k] > ava[k]) { 
                        boo = 1;
                        break;
                    }
                }
            
                if(boo == 0) { 
                    end[step++] = j; 

                    for(int l = 0; l < res; l++) 
                        ava[l] += all[j][l]; 
                    
                    fin[j] = 1; 
                }
            }
        }
    }


    int start = 1; 

    for(int i = 0; i < pro; i++) { 
        if(fin[i] == 0) { 
            start = 0;
            std::cout << "The Sequence Is Unsafe\n";
            break;
        }
    }
    if(start == 1) {
        std::cout << "The Safe Sequence Is: \n";
        
        for(int i = 0; i < pro - 1; i++) 
            std::cout << " P" << end[i] << " to"; 
        
        std::cout << " P" << end[pro-1] << '\n'; 
    }
    return 0;
}