#include "GeradorDeSenhas.h"
#include <stdlib.h>

void Mensagem(char SelectTexto, char escolha);

string AlimentadorSTRfila(char Escolha);

void AlimentarLog(char TipoRegistro,char TipoAtendimento, string NumeroNaOrdemClasse);
///kakakak///aa
int main() {

    while(true){

        Mensagem('M',' ') ;                     //Menu de classes

        char EntradaNaClasse(' ') ;
        cin >> EntradaNaClasse ;
        EntradaNaClasse = toupper(EntradaNaClasse) ;

        if ( EntradaNaClasse >= 'A' && EntradaNaClasse <='D') { // condicional com limite de escolhas

            string NumeroNaFilaClasse;
            NumeroNaFilaClasse = AlimentadorSTRfila(EntradaNaClasse);   //

            AlimentarLog('E', EntradaNaClasse, NumeroNaFilaClasse) ;
            Mensagem('R',EntradaNaClasse);              //mensagem de emissão de registro

        } else{
            Mensagem('S',EntradaNaClasse) ;             //mensagem de erro de opção
        }
    }
    return 0;
}
void Mensagem(char SelectTexto,char Escolha){

    switch (SelectTexto) {

        case ('M'):      //Menu Classes
            cout    <<"\nA- Atendimento prio 1\t"
                    <<"B- Atendimento prio 2\t "
                    <<"C- Atendimento prio 3\t"
                    <<"D- Atendimento prio 4\n"
                    <<">>>";
            break;

        case ('S'):     //Mensagem erro de escolha errada
            system("clear");
            cout<<RED"\nOpção {"<<Escolha<<"} não existe, escolha seu tipo de atendimento abaixo."<<NC<<endl;
            break;

        case ('R'):     // Registrado a opção
            system("clear");
            cout<<GRN"Opção Registrada, sua senha é :"<<NC;
            break;

        default:
            break;
    }
}