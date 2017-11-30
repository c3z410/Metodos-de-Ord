#include <fstream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>

using namespace std;

struct ponto{
    int x;
    int y;
    bool checked;
};

int media = 0;
int best = 0;

vector <struct ponto> reader(const char * str, int * nfac, int * range);

bool compare_v(vector<int>& a, vector<int>& b)
{
   return (a.size() >= b.size());
}

void Movvizinhanca(vector <struct ponto> clientes, int facilidades, int range, vector <int> * solution){
    int menor = INT_MAX;
    int menorindice;

    for(int i = 0; i < facilidades; i++){

        if(solution[i].size()-1 < menor){
            menor = solution[i].size()-1;
            menorindice = i;
        }
    }

    /*for(int i = 0;i != solution[menorindice].size();i++){
      clientes[solution[menorindice][i]].checked = false;
    }*/
    /*
    solution[menorindice].clear();
    vector <int> org[324];

    for (int k = 0; k != 323; k++){
      org[k].push_back(k);

      for (int l = k + 1; l != k; l = (l+1)%(clientes.size()-1)){

        float d = sqrt(((clientes[k].x - clientes[l].x)*(clientes[k].x - clientes[l].x)) + ((clientes[k].y - clientes[l].y)*(clientes[k].y - clientes[l].y)));
        if((d<=range) && !((clientes[k].checked) || (clientes[l].checked))) (org[k]).push_back(l);
      }
    }

    sort(begin(org),end(org),compare_v);

    solution[menorindice].push_back(org[0][0]);
    clientes[org[0][0]].checked = true;

    for(int j = 0; j < clientes.size(); j++){
      if(!(clientes[j].checked)){

          float dist = sqrt(((clientes[org[0][0]].x - clientes[j].x)*(clientes[org[0][0]].x - clientes[j].x)) + ((clientes[org[0][0]].y - clientes[j].y)*(clientes[org[0][0]].y - clientes[j].y)));

          if(dist <= range){
              (solution[menorindice]).push_back(j);
              clientes[j].checked = true;
          }
      }
    }*/

    for(int i = ((solution[menorindice])[0] + 1); i != (solution[menorindice])[0]; i = (i+1)%(clientes.size()-1)){

        if(!(clientes[i].checked)){

          vector <int> key = solution[menorindice];

          for(int u = 0;u != solution[menorindice].size()-1;u++){
            clientes[solution[menorindice][u]].checked = false;
          }

          //vector <int> key = solution[menorindice];

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
             for(int u = 0;u != solution[menorindice].size()-1;u++){
               clientes[solution[menorindice][u]].checked = false;
             }
             for(int u = 0;u != key.size()-1;u++){
               clientes[key[u]].checked = true;
             }
             solution[menorindice].clear();
             solution[menorindice]=key;
           }
        }
    }
}


void Solution(vector <struct ponto> clientes, int facilidades, int range, vector <int> * solution){


   srand(time(NULL));

   for(int i = 0; i < facilidades; i++){

       vector <int> org[324];
       for (int k = 0; k != 323; k++){
         org[k].push_back(k);
         for (int l = k + 1; l != k; l = (l+1)%(clientes.size()-1)){
           float d = sqrt(((clientes[k].x - clientes[l].x)*(clientes[k].x - clientes[l].x)) + ((clientes[k].y - clientes[l].y)*(clientes[k].y - clientes[l].y)));
           if((d<=range) && !((clientes[k].checked) || (clientes[l].checked))) (org[k]).push_back(l);
         }
       }

       sort(begin(org),end(org),compare_v);


       /*int meme = 0;
       for (int k = 323; k != 0; k--){
          if(org[k].size() > 1){
            meme = k;
            break;
          }
       }*/

      //int randomn = rand()%(int)((org[0].size() + org[meme].size())*0.5);
      float filtro = ((org[0].size() + org[323].size())*0.9);
      int mimd = 0;
      for (int k = 323; k != 0; k++){
         if(org[k].size() >= filtro){
           mimd = k;
           break;
         }
      }
      int randomn = rand()%(mimd);

      while(clientes[randomn].checked){

          randomn = rand()%(mimd);
      }
      //cout << randomn << endl;
      solution[i].push_back(randomn);
      //for(int n = 0; n < org[randomn].size(); n++){
      //  cout << org[randomn][0] << endl;
        clientes[randomn].checked = true;
      //}



       for(int j = 0; j < clientes.size()-1; j++){
           if(!(clientes[j].checked)){

               float dist = sqrt(((clientes[randomn].x - clientes[j].x)*(clientes[randomn].x - clientes[j].x)) + ((clientes[randomn].y - clientes[j].y)*(clientes[randomn].y - clientes[j].y)));

               if(dist <= range ){
                   (solution[i]).push_back(j);
                   clientes[j].checked = true;
               }
           }
       }
      //for (int z = 0; z != 323; z++) org[z].clear();
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

   //for(int h = 0; h < 5;h++)
   Movvizinhanca(clientes, facilidades, range, solution);

   cout << "\n\nCom Movimento de Vizinhanca: \n";

   count = 0;

   for(int i = 0; i < facilidades; i++){

       cout << "\nF " << solution[i][0] << "  --- C: ";

       for(int j = 1; j < solution[i].size(); j++){
           cout<< ((solution[i])[j]) << " ";
       }
       count += (solution[i]).size()-1;
   }

   cout << "\n\n"<< count <<" pontos cobertos \n";
   if(best < count)best = count;
   media += count;

}


int main(){

    int nfac, range;
    vector <struct ponto> clientes;
    clientes = reader("input.txt", &nfac, &range);

    //vector <int> solution [nfac];
    cout << "\n\n GRASP\n";


    for(int t=0; t < 9;t++){
      vector <int> solution [nfac];
      Solution(clientes, nfac, range, solution);
      //for (int z = 0; z != 20; z++){
       //fill(solution[z].begin(), solution[z].end(), 0);
       //solution[z].clear();
       //cout << solution[z].size() << endl;
     ///}
    }

    cout << "\n\n"<< best <<" BEST GRASP \n";
    cout << "\n\n"<< (media/10) <<" MEDIA GRASP \n";


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
