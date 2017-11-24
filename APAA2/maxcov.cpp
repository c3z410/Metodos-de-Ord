#include <fstream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <iostream>
#include <limits.h>
#include <vector>


using namespace std;

struct ponto{
    int x;
    int y;
    bool checked;
};

vector <struct ponto> reader(const char * str, int * nfac, int * range);

void Movvizinhanca(vector <struct ponto> clientes, int facilidades, int range, vector <int> * solution){
    int menor = INT_MAX;
    int menorindice;

    for(int i = 0; i < facilidades; i++){

        if(solution[i].size()-1 < menor){
            menor = solution[i].size()-1;
            menorindice = i;
        }
    }

    for(int i = 0;i != solution[menorindice].size();i++){
    clientes[solution[menorindice][i]].checked = false;
  }

    for(int i = ((solution[menorindice])[0] + 1); i != (solution[menorindice])[0]; i = (i+1)%(clientes.size()-1)){

        if(!(clientes[i].checked)){

          vector <int> key = solution[menorindice];

           solution[menorindice].clear();

           (solution[menorindice]).push_back(i);
           clientes[i].checked = true;

           for(int j = 0; j < clientes.size(); j++){
               if(!(clientes[j].checked)){

                   float dist = sqrt(((clientes[i].x - clientes[j].x)*(clientes[i].x - clientes[j].x)) + ((clientes[i].y - clientes[j].y)*(clientes[i].y - clientes[j].y)));

                   if(dist <= range){

                       (solution[menorindice]).push_back(j);
                       clientes[j].checked = true;
                   }
               }
           }
           if (solution[menorindice].size() < key.size()){
             solution[menorindice].clear();
             solution[menorindice]=key;
           }
        }
    }
}




 void Solution(vector <struct ponto> clientes, int facilidades, int range, vector <int> * solution){

    srand(time(0));


    for(int i = 0; i < facilidades; i++){

        int f = (rand()%(clientes.size()-1));

        while(clientes[f].checked){

            f = (rand()%(clientes.size()-1));
        }



        (solution[i]).push_back(f);
        clientes[f].checked = true;


        for(int j = 0; j < clientes.size(); j++){
            if(!(clientes[j].checked)){

                float dist = sqrt(((clientes[f].x - clientes[j].x)*(clientes[f].x - clientes[j].x)) + ((clientes[f].y - clientes[j].y)*(clientes[f].y - clientes[j].y)));

                if(dist <= range){
                    (solution[i]).push_back(j);
                    clientes[j].checked = true;
                }
            }
        }
    }


    int count = 0;

    for(int i = 0; i < facilidades; i++){

        cout << "\nF " << solution[i][0] << "  --- C: ";

        for(int j = 1; j < solution[i].size(); j++){
            cout<< ((solution[i])[j]) << " ";
        }
        count += (solution[i]).size()-1;
    }

    cout << "\n\n"<< count <<" pontos cobertos\n";

    for(int m = 0 ; m < 5 ; m++){
      Movvizinhanca(clientes, facilidades, range, solution);}

    cout << "\n\nCom Movimento de Vizinhanca: \n";

    count = 0;

    for(int i = 0; i < facilidades; i++){

        cout << "\nF " << solution[i][0] << "  --- C: ";

        for(int j = 1; j < solution[i].size(); j++){
            cout<< ((solution[i])[j]) << " ";
        }
        count += (solution[i]).size()-1;
    }

    cout << "\n\n"<< count <<" pontos cobertos :)\n";

 }




int main(){

    int nfac, range;
    vector <struct ponto> clientes;
    clientes = reader("input.txt", &nfac, &range);

    vector <int> solution [nfac];

    Solution(clientes, nfac, range, solution);

    return 0;
}







vector <struct ponto> reader(const char * str, int * nfac, int * range){

   ifstream file;
   file.open(str, ios::in);

   vector <struct ponto> aux;
   int x,y;
   struct ponto a;

   file >> x >> y >> *nfac >> *range;

   while(file.good()){
       file >> a.x >> a.y;
       a.checked = false;

       aux.push_back(a);

   }

   aux.erase(aux.end()-1);
   return aux;
}
