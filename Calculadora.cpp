#include <iostream>
#include <string>
using namespace std;

class Calculadora
{
public:
    double n1;
    double n2;

    Calculadora(double n1, double n2)
    {
        this->n1 = n1;
        this->n2 = n2;
    }

    double somar()
    {
        return this->n1 + this->n2;
    }

    double dividir()
    {
        if (this->n2 == 0)
        {
            cout << "numero Invalido, Divisao por 0";
            return 0;
        }
        else
        {
            return this->n1 / this->n2;
        }
    }

    double subtrair()
    {
        return this->n1 - this->n2;
    }

    double multiplicar()
    {
        return this->n1 * this->n2;
    }

    static int menu()
    {
        int op;
        cout << "Escolha uma opcao entre 1 a 4:\n";
        cout << "1-Somar\n";
        cout << "2-Dividir\n";
        cout << "3-Subtrair\n";
        cout << "4-Multiplicar\n";
        cin >> op;
        return op;
    }

    // Ele não está ligado a nenhuma variável específica da classe Calculadora. Ele apenas lê um número do usuário e o retorna.
    // Isso torna o método reutilizável para qualquer situação em que você precise ler um número, seja para n1, n2, ou qualquer outra variável.
    static double lernumero(const string &mensagem)
    {
        double numero;
        cout << mensagem;
        cin >> numero;
        return numero;
    }
};

int main()
{
    int operacao = Calculadora::menu();

    double resultado = 0;
    bool operacaovalida = true;

    // No código principal (main), você decide como usar o valor retornado por lernumero. Por exemplo:

    double n1 = Calculadora::lernumero("Digite o primeiro numero: ");
    double n2 = Calculadora::lernumero("Digite o segundo nu2mero: ");
    // Aqui, os valores retornados por lernumero são atribuídos às variáveis n1 e n2.

    Calculadora *calcu = new Calculadora(n1, n2);

    switch (operacao)
    {
    case 1:
        resultado = calcu->somar();
        break;
    case 2:
        resultado = calcu->dividir();
        break;
    case 3:
        resultado = calcu->subtrair();
        break;
    case 4:
        resultado = calcu->multiplicar();
        break;
    default:
        cout << "Opcao invalida" << endl;
        operacaovalida = false;
        break;
    }

    if (operacaovalida)
    {
        cout << "Resultado: " << resultado << endl;
    }

    delete calcu; // Libera a memória alocada
    return 0;
}