#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

class Sat {

    class Data {

             private:
                int clauseStart;
                int clauseLength;

            public:
                Data() { }
                Data(int initC,int endC) {
                    clauseStart = initC;
                    clauseLength = endC;
                }

            int getClauseStart() {

                return clauseStart;
            }

            int getClauseEnd() {

                return clauseLength;
            }
        };

    public:
        Sat() {}
        char *numClauses;
        char *numVariables;
        int nClauses;
        int nVariables;
        int clauseSize = 0;
        int greaterClause = 0;
        int startClause = 0;
        int endClause = 0;
        vector<int> clauses;
        vector<bool> variables;
        vector<Data> indices;

/*
    void criaArrayIndices (int inicio,int fim, int indice) {

    while (clauses.at(indice) != 0)
        Data d = Data(inicio,fim);
        indices.push_back(d);
    }
*/
    int getClauseStart (Data d) {

        return d.getClauseStart();
    }

    int getClauseEnd(Data d) {

        return d.getClauseEnd();
    }

    void criaArrayVar () {

        string num_variables = numVariables;
        nVariables = str_toint(num_variables);
        for (int i = 0; i <= nVariables; i++) {
            variables.push_back(false);
        }
    }
/*
    int convertLiteral (int literal) {

        if (literal > 0 ) {
            literal = literal*2;
            return literal;
        }
        else {
            literal = (2*literal)+1;
            return literal;
        }
    }
*/
    void numberClauses(string str) {

        char *number = new char[str.length()+1];
        std::strcpy(number,str.c_str());
        char *aux;
        int auxToint;
        numClauses = strtok(number," ");
        aux = numClauses;
        numVariables = strtok (NULL," ");
    }

    void leClausula (string str) {

        char *clause = new char[str.length() + 1];
        clauseSize = 0;
        std::strcpy(clause, str.c_str());
        char *literal;
        literal = strtok(clause," ");
        while (*literal != '0') {
            clauseSize++;

            cout << literal;
            cout << ' ';

            string lit = literal;
            int l = str_toint(lit);
            clauses.push_back(l);
            literal = strtok (NULL," ");
        }
        endClause = startClause + (clauseSize - 1);
        cout << '\n';
        cout << "inicio clausula: ";
        cout << startClause;
        cout << " fim clausula: ";
        cout << endClause;
        cout << '\n';
        cout << '\n';

        Data d = Data{startClause,endClause};
        indices.push_back(d);
        startClause = startClause + clauseSize;
    }

    void read () {

      string line;
      ifstream myfile ("C:/Users/Lisiane/arquivo.txt");
      int lengthArray = 0;
      if (myfile.is_open())
      {
        while ( getline (myfile,line) )
        {
          if (line.at(0) == 'p') {
                numberClauses(line);
                string clauses = numClauses;
                lengthArray = str_toint(clauses);
          }
          else if (!(line.at(0) == 'c')) {
            leClausula(line);
          }
        }
        criaArrayVar();
        myfile.close();
      }
      else cout << "Unable to open file";
    }

    int str_toint (string literal) {

        int literalValue = atoi(literal.c_str()); //value = 45
        return literalValue;
    }

    bool iniciaSolver() {

        vector<int> clausesCopy;
        clausesCopy = clauses;
    }

    bool solver(vector<int> clausesCopy) {

    //escolher variável
    //ir no array de variaveis e colocar valor no variavel
    //varrer vetor de clausulas
    }

};

int main()
{
    Sat s;
    s.read();
/*
  int i = 0;
   cout << "VETOR\n";
  for (i = 0; i < s.clauses.size(); i++) {

    cout << s.clauses.at(i);
    cout << '\n';
  }  */
/*
  int i = 0;
  cout << "INDICES\n";

  for (i = 0; i < s.indices.size(); i++) {

    cout << s.getClauseStart(s.indices.at(i));
    cout << '\n';
  }
*/
  //s.iniciaSolver();
    return 0;
}
