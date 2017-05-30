
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <windows.h>
#define max1 5000
#define max2 50000
#define max3 100000
using namespace std;

int conta=0,conto=0,contt=0;

void SS(int *vetor, int size){
	int i,j,min,aux,op;
	for(i=0;i<(size-1);i++){
		min=i;
    	for(j=(i+1); j<size; j++){
    		if(vetor[j]<vetor[min]){
    			min=j;
    		}
    		if(i!=min){
    			aux=vetor[i];
    			vetor[i]=vetor[min];
    			vetor[min]=aux;
    		}
    	}
    }	
    
}

void IS(int *vetor, int size){
	int i,j,aux;
	for(i=1; i<size; i++){
		aux=vetor[i];
		j=i-1;
    	while((j>=0) && (aux<vetor[j])){
    		vetor[j+1] = vetor[j];
	        j--;
    	}
    	vetor[j+1]=aux;
    }
}

int QS(int *vetor, int comeco, int fim){
	int pivot,aux,i=comeco,j=fim;
	pivot=vetor[(comeco+fim)/2];
	
	while(i<=j){
		while(vetor[i]<pivot){
			i++;
		}
		while(vetor[j]>pivot){
			j--;
		}
		if(i<=j){
			aux = vetor[i];
			vetor[i]=vetor[j];
			vetor[j]=aux;
			i++;
			j--;
		}
	}
	if(comeco<j){
		QS(vetor,comeco,j);
	}
	
	if(i<fim){
		QS(vetor,i,fim);
	}
}

int menu3(int *vetor,int *vetor1,int size,int t1,char *o){
	int sort;
	clock_t t;
	do{
       system("cls||clear");
       cout<<"Bem-vindo ao menu algoritmos de ordenacao!\n";
       cout<<"Escolha um dos algoritmos de ordenacao a seguir:\n\n";
       cout<<"1 - Selection Sort\n2 - Insertion Sort\n3 - Quick Sort\n4 - Exibir Vetor\n5 - Exibir Vetor Auxiliar\n6 - Exibir Relatorio\n";
       cout<<"0 - Voltar\n--> ";
       cin>>sort;
       switch(sort){
            case 1:{   
                system("cls||clear");
                cout<<"Selection Sort\n";
                for (int i = 0; i < size; i++){
				    vetor[i]=vetor1[i];
				}
				
				t = clock();
				SS(vetor,size);
				t=clock()-t;
				cout<<"A ordenacao levou "<<t*1.0/CLOCKS_PER_SEC<<" segundos.";
				
				conta++;
				
				ofstream myfile;
				myfile.open("Relatorio.txt",ios::app);
				myfile<<"__________________________________________\n\nAlgoritmo de Ordenacao ("<<conta<<"): Selection Sort\n\nOrdenacao de Vetor ("<<conto<<"): Ordem "<<o<<"\n\nTamanho do Vetor ("<<contt<<"): "<<t1<<" posicoes\n\nTempo de Ordenacao: "<<t*1.0/CLOCKS_PER_SEC<<" segundos\n"<<"\nHora e Data: "<<__TIME__<<" de "<<__DATE__<<"\n";
				myfile.close();
				cout<<"\n\nOs dados da ordenacao foram salvos com sucesso no arquivo!\n\n";
				cout<<"Voltando ao menu de algoritmos de ordenacao...";
				system("pause>nul");break;
            }
            case 2:{   
                system("cls||clear");
                cout<<"Insertion Sort\n";
                     
                for (int i = 0; i < size; i++){
				    vetor[i]=vetor1[i];
				}
                
                t= clock();
				IS(vetor,size);
				t=clock()-t;
				cout<<"A ordenacao levou "<<t*1.0/CLOCKS_PER_SEC<<" segundos.";
				
				
				conta++;
				
				ofstream myfile;
				myfile.open("Relatorio.txt",ios::app);
				myfile<<"__________________________________________\n\nAlgoritmo de Ordenacao ("<<conta<<"): Insertion Sort\n\nOrdenacao de Vetor ("<<conto<<"): Ordem "<<o<<"\n\nTamanho do Vetor ("<<contt<<"): "<<t1<<" posicoes\n\nTempo de Ordenacao: "<<t*1.0/CLOCKS_PER_SEC<<" segundos\n"<<"\nHora e Data: "<<__TIME__<<" de "<<__DATE__<<"\n";
				myfile.close();
				cout<<"\n\nOs dados da ordenacao foram salvos com sucesso no arquivo!\n\n";
				cout<<"Voltando ao menu de algoritmos de ordenacao...";
				system("pause>nul");break;
            }
            case 3:{   
                system("cls||clear");
                cout<<"Quick Sort\n";
                
                for (int i = 0; i < size; i++){
				    vetor[i]=vetor1[i];
				}
                
                int comeco=0,fim=(size-1),i;
                t= clock();
				QS(vetor,comeco,fim);
				t=clock()-t;
				cout<<"A ordenacao levou "<<t*1.0/CLOCKS_PER_SEC<<" segundos.";
				
				conta++;
				
				ofstream myfile;
				myfile.open("Relatorio.txt",ios::app);
				myfile<<"__________________________________________\n\nAlgoritmo de Ordenacao ("<<conta<<"): Quick Sort\n\nOrdenacao de Vetor ("<<conto<<"): Ordem "<<o<<"\n\nTamanho do Vetor ("<<contt<<"): "<<t1<<" posicoes\n\nTempo de Ordenacao: "<<t*1.0/CLOCKS_PER_SEC<<" segundos\n"<<"\nHora e Data: "<<__TIME__<<" de "<<__DATE__<<"\n";
				myfile.close();
				cout<<"\n\nOs dados da ordenacao foram salvos com sucesso no arquivo!\n\n";
				cout<<"Voltando ao menu de algoritmos de ordenacao...";
				system("pause>nul");break;
            }
            case 4:{
            	system("cls||clear");
            	cout<<"O vetor esta preenchido da seguinte maneira:\n";
			    cout<<"\n\n";
		    	for (int i = 0; i < size; i++){
					cout<<vetor[i]<<"\t";
				}
				cout<<"\n\nVoltando ao menu de algoritmos de ordenacao...";
				system("pause>nul");break;
				
            }
            case 5:{
            	system("cls||clear");
            	cout<<"O vetor auxiliar esta preenchido da seguinte maneira:\n";
			    cout<<"\n\n";
		    	for (int i = 0; i < size; i++){
					cout<<vetor1[i]<<"\t";
				}
				cout<<"\n\nVoltando ao menu de algoritmos de ordenacao...";
				system("pause>nul");break;
            }
            case 6:{
            	system("cls||clear");
            	string linha;
            	ifstream myfile ("Relatorio.txt");
            	if (myfile.is_open()){
            		while (getline(myfile,linha))
            		{
            			cout<<linha<<"\n";
            		}
            		myfile.close();
            	}
            	system("pause>nul");
            }
            case 0:{
                system("cls||clear");break;
            }
            default:{
                system("cls||clear");
                cout<<"Opcao invalida!\nTente Novamente...";
                system("pause>nul");
                system("cls||clear");break;
            }
        }
    }while(sort);
}

int menu2(int *vetor,int *vetor1,int size,int t){
	int ordem;
	do{
		int op,a=0,pc,cont=0,l,p=1;
		char *o,c=219;
        system("cls||clear");
        cout<<"Bem-vindo ao menu de ordenacao!\n";
        cout<<"Escolha uma das ordenacoes de vetor a seguir:\n\n";
        cout<<"1 - Ordem Aleatoria\n2 - Ordem Decrescente\n3 - Ordem Crescente\n4 - Exibir Vetor (Disponivel somente apos a ordenacao do vetor)\n5 - Exibir Vetor Auxiliar (Disponivel somente apos a ordenacao do vetor)\n";
        cout<<"0 - Voltar\n--> ";
        cin>>ordem;
        switch(ordem){
            case 1:{  
				cout<<"\nOrdenando...\n";
                srand((unsigned)time(NULL));
				for (int i = 0; i < size; i++){
					pc=(i*100)/size;
	            	l=(cont*size)/100;
	            	if(i==l)
	            	{
	            		Sleep(10);
	            		if(cont==99){
	            			cont=100;
	            			pc++;
	            		}
	            		cout<<"\r"<<pc<<"% ";
	            		if(cont%5==0){
	            			p++;
	            			for(i=1;i<=p;i++)
	            			{
		            		cout<<c;
		            		}
	            		}
	            		cont++;
	            	}
				    vetor[i] = rand();
				    vetor1[i]=vetor[i];
				}
				Sleep(1000);
				conto++;
				o="Aleatoria";
				menu3(vetor,vetor1,size,t,o);
				a++;break;
            }
            case 2:{
				cout<<"\nOrdenando...\n";
	            for(int i=0;i<size;i++){
	            	pc=(i*100)/size;
	            	l=(cont*size)/100;
	            	if(i==l)
	            	{
	            		Sleep(10);
	            		if(cont==99){
	            			cont=100;
	            			pc++;
	            		}
	            		cout<<"\r"<<pc<<"% ";
	            		if(cont%5==0){
	            			p++;
	            			for(i=1;i<=p;i++)
	            			{
		            		cout<<c;
		            		}
	            		}
	            		cont++;
	            	}
					vetor[i]=size-i;
					vetor1[i]=vetor[i];
				}
				Sleep(1000);
				conto++;
				o="Decrescente";
				menu3(vetor,vetor1,size,t,o);
				a++;break;
            }
            case 3:{
				cout<<"\nOrdenando...\n";
	            for(int i=0;i<size;i++){
	            	pc=(i*100)/size;
	            	l=(cont*size)/100;
	            	if(i==l)
	            	{
	            		Sleep(10);
	            		if(cont==99){
	            			cont=100;
	            			pc++;
	            		}
	            		cout<<"\r"<<pc<<"% ";
	            		if(cont%5==0){
	            			p++;
	            			for(i=1;i<=p;i++)
	            			{
		            		cout<<c;
		            		}
	            		}
	            		cont++;
	            	}
					vetor[i]=i+1;
					vetor1[i]=vetor[i];
				}
				Sleep(1000);
				conto++;
				o="Crescente";
				menu3(vetor,vetor1,max1,t,o);
				a++;break;
            }
            case 4:{
            	system("cls||clear");
            	if(a!=0){
            		cout<<"O vetor esta preenchido da seguinte maneira:\n";
				    cout<<"\n\n";
			    	for (int i = 0; i < size; i++){
						cout<<vetor[i]<<"\t";
					}
				}
				else{
					cout<<"O vetor precisa primeiro estar ordenado para ser exibido!\nEscolha uma das opcoes de ordem do menu de ordenacao de vetores.";
				}
					
				cout<<"\n\nVoltando ao menu de ordenacao de vetores...";
				system("pause>nul");break;
            }
            case 5:{
            	system("cls||clear");
            	if(a!=0){
            		cout<<"O vetor esta preenchido da seguinte maneira:\n";
				    cout<<"\n\n";
			    	for (int i = 0; i < size; i++){
						cout<<vetor[i]<<"\t";
					}
				}
				else{
					cout<<"O vetor precisa primeiro estar ordenado para ser exibido!\nEscolha uma das opcoes de ordem do menu de ordenacao de vetores.";
				}
				
				cout<<"\n\nVoltando ao menu de ordenacao de vetores...";
				system("pause>nul");break;
            }
            case 0:{
                system("cls||clear");break;
                
            }
            default:{
                system("cls||clear");
                cout<<"Opcao invalida!\nTente Novamente...\n";
                system("pause>nul");
                system("cls||clear"); break;  
            }
        }
    }while(ordem);
}

int menu1(){
	int *vetor,*vetor1,size;
	do{
       system("cls||clear");
       cout<<"Bem-vindo ao menu de tamanhos de vetores\n";
       cout<<"Escolha um dos tamanhos de vetor a seguir:\n\n";
       cout<<"1 - 5000\n2 - 50000\n3 - 100000\n";
       cout<<"0 - Sair\n\n--> ";
       cin>>size;
       switch(size){
            case 1:{   
                system("cls||clear");
                
                vetor=(int*) malloc(max1 * sizeof(int ));
                vetor1=(int*) malloc(max1 * sizeof(int ));
                contt++;
                menu2(vetor,vetor1,max1,max1);break;
            }
            case 2:{   
                system("cls||clear");
                
                vetor=(int*) malloc(max2 * sizeof(int ));
                vetor1=(int*) malloc(max2 * sizeof(int ));
                contt++;
                menu2(vetor,vetor1,max2,max2);break;
            }
            case 3:{   
                system("cls||clear");
                
                vetor=(int*) malloc(max3 * sizeof(int ));
                vetor1=(int*) malloc(max3 * sizeof(int ));
                contt++;
                menu2(vetor,vetor1,max3,max3);break;
            }
            case 0:{
                system("cls||clear");;break;
            }
            default:{
                cout<<"Opcao invalida!\nTente Novamente...";
                system("pause>nul");
                system("cls||clear");break;
            }
        }
    }while(size);
}


int main(void){
    menu1();
    int se;
    cout<<"Deseja exibir o relatorio antes de sair?\n0 - Nao\n1 - Sim\n--> ";
    cin>>se;
    if(se==1){
    	system("cls||clear");
    	string linha;
		ifstream myfile ("Relatorio.txt");
		if (myfile.is_open()){
			while (getline(myfile,linha))
			{
				cout<<linha<<"\n";
			}
			myfile.close();
		}
		system("pause>nul");
		
	}
}
