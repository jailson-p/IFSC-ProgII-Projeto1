//
// Created by jailson on 21/06/2021.
//

#ifndef SISTEMADEATENDIMENTO_GERADORDESENHAS_H
#define SISTEMADEATENDIMENTO_GERADORDESENHAS_H

#define NC "\e[0m"                  //
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYNB "\e[30;46m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

#include <ctime>
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <list>
#include <queue>
#include <stack>

using namespace std;

void Mensagem(char SelectTexto,char Escolha){ //função de mensagens

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
            cout<<GRN"Opção Registrada, sua senha é :"<<NC; //
            break;

        case ('D'):
            cout<<endl<<"Digite "<<GRN<<"{-}"<<NC<<" para chamar o próximo >>";
            break;

        default:
            break;
    }
}                   //função de mensagens

string DATAparaLog(){
    time_t data_tempo ;
    time ( &data_tempo ) ;

    struct tm*tempo = localtime ( &data_tempo ) ;
    struct tm*data = localtime ( &data_tempo ) ;

    string ano = to_string (data->tm_year + 1900 ) ;

    string mes = to_string (data->tm_mon + 1 ) ;
    if(mes.length() != 2){mes.insert(0, "0") ; } ;

    string dia = to_string( data->tm_mday );
    if(dia.length() != 2) { dia.insert(0,"0" ); };

    string hora = to_string( tempo->tm_hour );
    if(hora.length() != 2) { hora.insert(0,"0" ); };

    string min =  to_string( tempo->tm_min );
    if(min.length() != 2) { min.insert(0,"0" ); };

    string seg = to_string( tempo->tm_sec );
    if(seg.length() != 2) { seg.insert(0,"0" ); };

    string wd(ano + " " + mes + " " + dia + " " + hora + " " + min + " " + seg + " " );

    return wd;
}                                           //função manipulação de data para o .log

void AlimentarLog( char EstadoAtendimento , string ClasseNum ){ //char {Entrada,Saida,Atendimento},char classes, string numero sequeincial dentro da classe

    ofstream Atendimento("Atendimento.log",ios::app) ;

    if(Atendimento.is_open()){

        Atendimento << DATAparaLog() <<"\t"<< ClasseNum << "\t" << EstadoAtendimento << endl;

    }else {
        cout<<"erro Atendimento.log";
    }

    Atendimento.close();
}    //Alimentador do .log

string AlimentadorSTRfila ( char EntradaNaClasse , list<string> &listaorganizada,bool &IN) { //Entrada na "fila"

            string ClasseNum ;
            ClasseNum.push_back ( EntradaNaClasse ) ;
            if (IN){
                listaorganizada.push_back ( ClasseNum ) ;
                Mensagem ('R' , EntradaNaClasse ) ;              //mensagem de emissão de registro
                AlimentarLog ('E' , ClasseNum ) ;
            }
            else{

                AlimentarLog ('S' , listaorganizada.front() ) ;
                listaorganizada.pop_front();
                IN = true;
            }
            int NumAtenimento ;
    //      motor de enfileramento gera a senha do usuáro apartir da EntradaNaClasse e envipa para ClassNum (ex A002)

            return ClasseNum ;
}               //Entrada na "fila"

void verlist ( list<string> lista ) {
    for ( auto & it : lista ) {
        cout << REDB << it << NC << "\t" ;
    }
}
#endif //SISTEMADEATENDIMENTO_GERADORDESENHAS_H
