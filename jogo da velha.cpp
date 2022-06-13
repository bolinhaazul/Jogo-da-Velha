#include <iostream>
using namespace std;

void comec(int tabuleiro[][3]);       // incializa o tabuleiro com 0
char printtab(int bloco);             // imprime cada bloco do tabuleiro
void mostra(int tabuleiro[][3]);      // mostra o tabuleiro
void jogada(int tabuleiro[][3], int); // faz a jogada
int verifica(int tabuleiro[][3]);     // verifica se ainda tem espaço para jogar
int vitoria(int tabuleiro[][3]);      // verifica se alguém venceu
int jogo(int tabuleiro[][3]);         // faz o jogo
void placar(int, int &, int &);        // mostra o placar
int main()
{
    int tabuleiro[3][3];
    int jogador1 = 0, jogador2 = 0, resultado, continuar = 0;
    do
    {
        comec(tabuleiro);
        resultado = jogo(tabuleiro);                   // faz o jogo
        mostra(tabuleiro);                             // mostra o tabuleiro
        placar(resultado, jogador1, jogador2);         // mostra o placar
        cout << "\n Jogar novamente? (1-sim/0-nao): "; // pergunta se quer jogar novamente
        cin >> continuar;
    } while (continuar);
    return 0;
}
void comec(int tabuleiro[][3]) // incializa o tabuleiro com 0
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            tabuleiro[i][j] = 0;
}
char printtab(int bloco) 
{/* verifica o que imprimir em cada bloco do tabuleiro */
    if(bloco == 0)
        return ' ';
    else if(bloco == 1)
        return 'X';
    else
        return 'O';
}
void mostra(int tabuleiro[0][3]) // mostra o tabuleiro
{
    cout << endl;
    for (int linha = 0; linha < 3; linha++)
    {
        cout << " " << printtab(tabuleiro[linha][0]) << "|";
        cout << " " << printtab(tabuleiro[linha][1]) << "|";
        cout << " " << printtab(tabuleiro[linha][2]) << endl;

        if (linha != 2)
        {
            cout << "__ __ __" << endl;
        }
    }
}
void jogada(int tabuleiro[][3], int jogador) // faz a jogada
{
    int linha, coluna, verif;
    do
    {
        cout<<"Linha: ";
        cin>>linha;
        cout<<"Coluna: ";
        cin>>coluna;
        linha--; coluna--;
        verif = tabuleiro[linha][coluna] || linha < 0 || linha > 2 || coluna < 0 || coluna > 2;
        /* verifica se o espaço está vazio e se a linha e coluna estão dentro do tabuleiro */
        if (verif)
            cout << "Jogada invalida!\n";
    } while (verif);
    
    if (jogador==0) // se for o jogador 1 
    {
        tabuleiro[linha][coluna] = 1;
    }
    else if(jogador==1) // se for o jogador 2
    {
        tabuleiro[linha][coluna] = -1;
    }
    
}
int verifica(int tabuleiro[][3])// verifica se ainda tem espaço para jogar
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) // percorre o tabuleiro
            if (tabuleiro[i][j] == 0)
                return 1;
    return 0;
}
int vitoria(int tabuleiro[][3])//verifica se alguém venceu
{
    int linha, coluna, verif;
    /* verificando as linhas */
    for(linha=0;linha<3;linha++)//percorre as linhas
    {
        verif=0;
        for(coluna=0;coluna<3;coluna++)//percorre as colunas
        verif+=tabuleiro[linha][coluna];
        if(verif==3)
            return 1;
        else if(verif==-3)
            return -1;
    }
    /* verificando as colunas */
    for(coluna=0;coluna<3;coluna++) // percorre as colunas
    {
        verif=0;
        for(linha=0;linha<3;linha++)
            verif+=tabuleiro[linha][coluna]; // soma os valores das colunas
        if(verif==3) // se todas as colunas da linha tiverem o mesmo valor, o jogador 1 venceu
            return 1;
        if(verif==-3) // se todas as colunas da linha tiverem o mesmo valor, o jogador 2 venceu
            return -1;
    }
    /* verificando as diagonais */
    verif=0;
    for(linha=0;linha<3;linha++) 
        verif+=tabuleiro[linha][linha]; // soma os valores das diagonais
    if(verif==3) // se a soma da diagonal for 3, o jogador 1 venceu
        return 1;
    if(verif==-3) // se a soma da diagonal for -3, o jogador 2 venceu
        return -1;
        return 0;
}
int jogo(int tabuleiro[][3])//roda o jogo
{
    int vez=0, verif, vence;
    do
    {
        mostra(tabuleiro); // mostra o tabuleiro
        cout<<"Jogador "<<(vez%2+1)<<"\n"; // mostra o jogador
        jogada(tabuleiro, vez%2); // faz a jogada
        vez++; // passa para o próximo jogador
        verif = verifica(tabuleiro); // verifica se ainda tem espaço para jogar
        vence = vitoria(tabuleiro); // verifica se alguém venceu
    }while(verif && !vence); // enquanto houver espaço para jogar e ninguém venceu
    if(vence==1)//verifica se o jogador 1 venceu
    {
        cout<<"Jogador 1 venceu!\n"<<endl;
        return 1;
    }else
        if(vence==-1)//verifica se o jogador 2 venceu
        {
            cout<<"Jogador 2 venceu!\n"<<endl;
            return 2;
        }
    else
        cout<<"Nao ha vencedores!\n"<<endl;
        return 0;
}
void placar(int resultado, int &jogador1, int &jogador2)
{ /* atualiza o placar */
    if(resultado==1)
        jogador1++;
    else if(resultado==2)
        jogador2++;
    
    cout<<"Placar: "<<endl;
    cout<<jogador1<<" x "<<jogador2<<endl; // mostra o placar
}
