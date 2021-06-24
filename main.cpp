#include "GeradorDeSenhasComLog.h"

void verlist(list<string> lista);

int main(int argc,char *argv[]) {

    list<string> ListaAtendimento ;

    while(true){

        Mensagem('M',' ') ;                     //Menu de classes

        bool InOrOut = true;

        char EntradaNaClasse(' ') ;
        cin >> EntradaNaClasse ;
        EntradaNaClasse = toupper(EntradaNaClasse) ;

        if ( EntradaNaClasse >= 'A' && EntradaNaClasse <='D') { // condicional limitando as escolhas
            //Condição para CLIENES: entrar na "fila"

            AlimentadorSTRfila(EntradaNaClasse, ListaAtendimento, InOrOut) ;

        }
        else if ( isdigit( EntradaNaClasse ) ) {

            verlist (ListaAtendimento ) ;                       // Descarrega LISTA na tela

            Mensagem('D',' ') ;                     //Mensagem de comando de decremento

            cin >> EntradaNaClasse;
            if (EntradaNaClasse == '-'){//

                if ( ListaAtendimento.empty() ) {   break;     }  //Fecha COM A LISTA ESVAZIADA

                cout <<endl<<GRN<<"Chamando : "<<NC<<CYNB<< ListaAtendimento.front()<<NC<<"\n\n\n\n";

                InOrOut = false;

                AlimentadorSTRfila(EntradaNaClasse, ListaAtendimento, InOrOut) ;
            }    //Condição para Atendente: registra o que foi atendido em Saida no log, tira da "fila" e chama o próximo
        }
        else {
            Mensagem ('S' , EntradaNaClasse ) ;             //mensagem de erro de opção
        }
    }
    return 0;
}

