//
// Created by jailson on 21/06/2021.
//

#ifndef SISTEMADEATENDIMENTO_LOGFILE_H
#define SISTEMADEATENDIMENTO_LOGFILE_H

#include <ctime>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

string DATAparaLog(){
    time_t data_tempo;
    time(&data_tempo);

    struct tm*tempo = localtime(&data_tempo);
    struct tm*data = localtime(&data_tempo);

    string ano = to_string(data->tm_year + 1900);

    string mes = to_string(data->tm_mon + 1);
    if(mes.length() != 2){mes.insert(0,"0");};

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
}

void AlimentarLog(char TipoDeRegistro,char TipoAtendimento, string NumeroNaOrdemClasse){
    string Registro;
    Registro = TipoAtendimento;
    Registro.insert(0, DATAparaLog());

    ofstream Atendimento("Atendimento.log",ios::app) ;

    if(Atendimento.is_open()){
        Atendimento << Registro << NumeroNaOrdemClasse << " " << TipoDeRegistro  <<endl;
    }else {
        cout<<"erro Atendimento.log";
    }
    Atendimento.close();
}

#endif //SISTEMADEATENDIMENTO_LOGFILE_H

