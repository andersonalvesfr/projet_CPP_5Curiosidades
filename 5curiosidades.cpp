#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <locale.h>
using namespace std;

int numero_de_curios_pedido;
vector<string> curiosidades_do_arquivo;

vector<string> le_banco_de_curiosidades(){
    ifstream banco_de_curiosidades; //declara a variável arquivo com as palavras
    banco_de_curiosidades.open("Curiosidades.txt"); //abre o arquivo com as palavras

    if (banco_de_curiosidades.is_open()){//verifica se o arquivo txt foi aberto, antes de executar o código

        int quantidade_de_curiosidades;
        banco_de_curiosidades >> quantidade_de_curiosidades; //le a primeira linha do arquivo que contém o número de palavras, no caso o 5
  
        for(int j=0; j<quantidade_de_curiosidades; j++){
            string curiosidade_lida;
            banco_de_curiosidades >> curiosidade_lida; //envia a palavra que está no arquivo para a variável palavra lida
            curiosidades_do_arquivo.push_back(curiosidade_lida); //carrega no vetor a ultima curiosidade            
        }
        
       banco_de_curiosidades.close();
       return curiosidades_do_arquivo;
    }
    else {//caso não de para abrir o arquivo
    cout<< "Não foi possível acessar o banco de curiosidades, mova o arquivo Curiosidades.txt para o mesmo local deste arquivo" <<endl;
    exit(0); //para de executar o programa na HORA!
    }

}

void salva_curiosidade (vector<string> nova_lista){
    ofstream banco_de_curiosidades;//para escrever valores no arquivo
    banco_de_curiosidades.open("Curiosidades.txt");

    if (banco_de_curiosidades.is_open()){
        banco_de_curiosidades <<nova_lista.size() <<endl;//coloca na primeira linha o número de palavras que o arquivo contém

        for (string palavra : nova_lista){
            banco_de_curiosidades << palavra <<endl;
        }
        banco_de_curiosidades.close(); 
        }

    else {
        cout<< "Não foi possível acessar o banco de palavras" <<endl;
        exit(0); //para de executar o programa na HORA!
    }
        
}

void adiciona_nova_curiosidade(){
        cout <<"Digite a nova curiosidade, usando o underline (___) no lugar do espaço"<<endl;
        string nova_curiosidade;
        cin >>nova_curiosidade;
        vector<string> lista_de_curiosidades = le_banco_de_curiosidades(); //cria um vetor para guardar as palavras como se fosse uma lista
                                                //e chama a função le_arquivo
    lista_de_curiosidades.push_back(nova_curiosidade);

    salva_curiosidade(lista_de_curiosidades);

}



int main(){
     setlocale(LC_ALL, "Portuguese_Brasil");
     //para compilar mingw32-make 5curiosidades
     //codigo para o cmd rodar em utf-8: chcp 65001
    //>perguntar quantas curiosidades aleátorias a pessoa quer?
    //>mostrar as curiosidade de acordo com o banco de curiosidades
    //>adicionar a curiosidade
    
    cout <<"********Bem-vindo ao gerador de curiosidades********"<< endl;
    cout <<"********Criado por Anderson Alves Francisco ********"<< endl;

    cout <<"Digite o número de curiosidades que deseja receber"<< endl; //colocar depois o numero máximo
    cin >> numero_de_curios_pedido;
    cout <<"Você pediu "<< numero_de_curios_pedido<<" curiosidades:"<< endl;

    //vector<string> le_arquivo (); //le as palavras no arquivo txt
    le_banco_de_curiosidades();

        srand(time(NULL)); //inicializa a semente em zero
        vector<string>numero_de_curiosidades = le_banco_de_curiosidades();
        
        for(int k=0; k<numero_de_curios_pedido;k++){        
        int indice_sorteado = rand() % numero_de_curiosidades.size(); //define o número máximo de palavras sorteadas de acordo com o número de palavras no arquivo txt
        cout <<curiosidades_do_arquivo[indice_sorteado]<<endl;
        cout <<endl;
        }
 
    
    cout <<"Vc deseja inserir alguma curiosidade? (S/N)"<<endl;    
    char escolha;
    cin >>escolha;
    if (escolha == 'S'){
        adiciona_nova_curiosidade();
    }
    
    else{
    cout <<"*****Obrigado por utilizar o 5curiosidades, até mais!*****"<<endl;
    } 

}