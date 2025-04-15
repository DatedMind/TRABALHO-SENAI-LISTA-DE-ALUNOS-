#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>

using namespace std;


#define RESET "\033[01m"
#define INV "\033[8m"

/* 				RGB 				*/

#define COR_PRETO "\033[38;2;0;0;0m"
#define COR_BRANCO "\033[38;2;255;255;255m"
#define COR_VERMELHA "\033[38;2;255;0;0m"
#define COR_VERDE "\033[38;2;0;255;100m"
#define COR_AZUL "\033[38;2;0;0;255m"
#define COR_AMARELO "\033[38;2;255;255;0m"
#define COR_LARANJA "\033[38;2;250;150;0m"
#define COR_ROXO "\033[38;2;150;0;255m"


void ativar_ansi() {
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
DWORD dwMode = 0;
GetConsoleMode(hOut, &dwMode);
dwMode |= 0x004;
SetConsoleMode(hOut, dwMode);
}

struct medida_aluno {
   
	string nome;
    float altura;
    float peso;
   
};

medida_aluno alunos[] = {
		{"Daniel", 180, 80},
        {"Gustavo", 169, 90},
        {"Andre", 183, 92},
        {"Felipe", 176, 67},
        {"Davi", 166, 67},
        {"Kaua", 182, 76},
        {"Roveda", 185, 62},
        {"Isa", 160, 63},
        {"Vitor", 170, 40},
        {"Jessica", 175, 50},
        {"Joao", 165, 65},
        {"Wilson", 167, 60},
        {"Nicollas", 176, 76},
        {"Kevin", 175, 65},
        {"Jizele", 160, 55},
        {"Pedro", 166, 52},
        {"Mateus", 170, 65}
       
};

int numAlunos = sizeof(alunos) / sizeof(alunos[0]);

void pesquisarAluno() {
   
string nome;
   
    cout << COR_BRANCO << "\nDigite o nome do aluno(a) que deseja pesquisar: " << COR_LARANJA;
    cin >> nome;
   
    system("cls");
    
    transform(nome.begin(), nome.end(), nome.begin(), ::toupper);

	bool encontrado = false;

    for (int i = 0; i < numAlunos; i++) {
       
        string nomeAluno = alunos[i].nome;
        
        transform(nomeAluno.begin(), nomeAluno.end(),nomeAluno.begin(), ::toupper);
        
		if (nomeAluno == nome) {
           
			cout << COR_LARANJA << "\nMedidas do Aluno(a): " << COR_BRANCO << alunos[i].nome << endl;
            cout << COR_BRANCO << "Altura: " << alunos[i].altura << "cm" << endl;
            cout << COR_BRANCO << "Peso: " << alunos[i].peso << "kg" << endl;
           
            cout << endl << COR_LARANJA;
         
		     encontrado = true;
		     break;
			
        }
        
        
    }
	if (encontrado == false){
 			cout << endl << COR_VERMELHA << "Aluno não encontrado.\n" << endl;
	} 
	

}

void tabelaAlunos (){
	
	for (int i = 0; i <= numAlunos - 1; i++) {
 
		cout << COR_LARANJA << alunos[i].nome;
		cout << COR_BRANCO<< "     \tAltura: " << alunos[i].altura << "cm";
		cout << COR_BRANCO << "    \tPeso: " << alunos[i].peso << "kg" << endl;

	}
 
 
}

void letreiroSair (){

     string palavra = "SAINDO...";

	for (int i = 0; i < palavra.length(); i++) {
	     
	cout << COR_VERMELHA << palavra[i];
	Sleep(50);
	
	}

cout << COR_ROXO <<"\n\n\n\n\n\t\t\t\t=)";
}

void menu () {

	cout << COR_VERDE<< "777";
	cout << COR_VERDE << "\n\tMedidas dos Alunos SENAI\n" << endl;
	cout << COR_BRANCO << "Opções:" << endl;
    cout << COR_VERDE << "[1] Lista de Alunos do SENAI cadastrados " << COR_BRANCO << "(" << numAlunos << ")" << endl;
    cout << COR_VERDE <<"[2] Pesquisar aluno" << endl;
    cout << COR_AMARELO << "[0] Sair" << endl;
    cout << COR_BRANCO << "Escolha uma opção: " << COR_VERDE;

}

void code () {

int opcao;
    do {

	menu ();

        cin >> opcao;

        switch (opcao) {

		case 1:
           
            system("cls");
            cout << "\n"
			COR_LARANJA << "total de Alunos do SENAI cadastrados: "<< COR_BRANCO << "(" << numAlunos << ")"
			<< endl << endl;
		
		tabelaAlunos ();
   
		cout << COR_LARANJA << endl;
   
		
		
		
		system("pause");
		system("cls");
       
       
       
		break;
           
    	case 2:
           
			system("cls");
				
                pesquisarAluno();
                
		system("pause");
		system("cls");
               
		break;

    	default:
           
            system("cls");
           
            cout << endl;
            cout << COR_VERMELHA << "Opção inválida." << endl;
			cout << endl;
               
		system("pause");
		system("cls");


    	break;
           
    	case 0:
           
			system("cls");
           	
           	cout << "\n";
			letreiroSair ();
			cout << COR_PRETO << INV << endl;
 
		break;
           
           
           
		case 777:
       
       
        system("cls");
       
        	cout << COR_VERDE << "\nA vida é como um jogo de futebol, \nvocê precisa ter estratégia,\n habilidade e perseverança para vencer, \nassim como o Coritiba busca a "<< COR_BRANCO << "\nvitória em cada partida, e um \nprofessor do SENAI busca transmitir \nconhecimento e inspirar seus\n alunos a alcançar seus objetivos." << endl;
        	cout << COR_VERDE << endl;
        
        system("pause");
        system("cls");
       
       
		break;  

	  	}	
       
       
    } while (opcao != 0);

}

int main() {

ativar_ansi ();

setlocale(LC_ALL, "portuguese");

code ();


    return 0;
}