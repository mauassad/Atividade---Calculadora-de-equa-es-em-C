#include <stdio.h> // biblioteca com funcao printf
#include <math.h> // biblioteca com funcoes da matematica, ex: sqrt
#include <locale.h> // biblioteca para expressoes da lingua portuguesa

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    int opcao;
    int continuar = 1;
    // Menu de opcoes para o usuario escolher
    while (continuar == 1) {
        printf("\n======== CALCULADORA DE EQUACOES ========\n");
        printf("1 - Resolver equacao do primeiro grau (ax + b = 0)\n");
        printf("2 - Resolver equacao do segundo grau (ax^2 + bx + c = 0)\n");
        printf("3 - Sobre o programa\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
   // Caso usuario digite termo fora das opcoes do menu, print mensagem de erro e volta para o menu.
         if (scanf("%d", &opcao) != 1) {
            printf("Opcao inexistente");
            scanf("%*s");
            continue;
        }
  // Caso a equacao de primeiro grau seja escolhida pelo usuario, pede os dados da equacao e mostra a resolucao.
      if (opcao == 1) {
            double a, b, x;
            printf("\nResolucao passo-a-passo: Equacao do Primeiro Grau ---\nForma: ax + b = 0\n");

            printf("Digite o valor de a: ");
            if (scanf("%lf", &a) != 1) { printf("Valor invalido.\n"); scanf("%*s"); continue; } // caso o usuario digite um valor invalido, mostra mensagem de erro e volta para o Menu.

            printf("Digite o valor de b: ");
            if (scanf("%lf", &b) != 1) { printf("Valor invalido.\n"); scanf("%*s"); continue; } // caso o usuario digite um valor invalido, mostra mensagem de erro e volta para o Menu.

            if (a == 0.0) {
                if (b == 0.0) {
                    printf("a e b devem ser diferentes de 0. Infinitas solucoes.\n");
                } else {
                    printf("a e b devem ser diferentes de 0. Infinitas solucoes.\n");
                }
            } else {  // Mostra a resolucao passo a passo da equacao de primeiro grau.

                printf("\nEquacao informada: %.fx + %.f = 0\n",a, b);
                printf("\nPassos: \n");
                printf("1) Escreva a equacao: %.fx + %.f = 0\n", a, b);
                printf("2) Isolar termo com x: %.fx = -(%.f)\n", a, b);
                printf("   ou %.fx = %.f\n",a, -b);
                printf("3) x = %.f / %.f\n",-b, a);
                x = -b / a;
                printf("4) Solucao: x = %.2f\n", x);

            }

        } else if (opcao == 2) { // Caso a equacao de segundo grau seja escolhida, pede os valores de a, b, c para o usuario..
            double a, b, c, delta, x1, x2;
            printf("\n=== Equacao do Segundo grau: ax^2 + bx + c = 0 ===\n");

                //Pede o valor de a b e c para o usuario, caso algum valor seja invalido, mostra mensagem de erro e volta para o menu.
            printf("Digite o valor de a: ");
            if (scanf("%lf", &a) != 1) { printf("Valor invalido.\n"); scanf("%*s"); continue; }

            printf("Digite o valor de b: ");
            if (scanf("%lf", &b) != 1) { printf("Valor invalido.\n"); scanf("%*s"); continue; }

            printf("Digite o valor de c: ");
            if (scanf("%lf", &c) != 1) { printf("Valor invalido.\n"); scanf("%*s"); continue; }

            if (a == 0.0) {  // Verifica se uma das variaveis tem o valor de zero.

                if (b == 0.0) {
                    if (c == 0.0) {  // Se b ou c possuir o valor de zero, equacao sem solucao
                        printf("a=0, b=0, c=0 → infinitas solucoes.\n");
                    } else {
                        printf("a=0, b=0, c!=0 → sem solucao.\n");
                    }
                } else { // Se a possuir valor de zero, converte a equacao de segundo grau para primeiro grau e mostra o resultado.
                    double x = -c / b;
                    printf("Equacao convertida para primeiro grau: \n");
                    printf("\nEquacao informada: %.fx + %.f = 0\n",b, c);
                    printf("\nPassos: \n");
                    printf("1) Escreva a equacao: %.fx + %.f = 0\n", b, c);
                    printf("2) Isolar termo com x: %.fx = -(%.f)\n", b, c);
                    printf("   ou %.fx = %.f\n",b, -c);
                    printf("3) x = %.f / %.f\n",-c, b);
                    x = -c / b;
                    printf("4) Solucao: x = %.2f\n", x);
                }
            } else { //Se os valores informados forem validos, mostra o passo a passo para calcular Delta.
                printf("\nEquacao informada: %.fx^2 + %.fx + %.f = 0.\n", a, b, c);
                printf("\nPassos: Identifique os coeficientes:\n");
                printf("a = %.f (o numero que acompanha o x^2)\n",a);
                printf("b = %.f (o numero que acompanha o x)\n",b);
                printf("c = %.f (o termo independente)\n",c);
                printf("\n1) Calcule o discriminante: Delta = b^2 - 4*a*c\n");
                printf("\nSubstitua os valores de a, b, c na formula de delta.\n");
                printf("Delta = %.f^2 - 4*%.f*%.f\n", b, a, c);
                printf("Delta = %.f - %.f\n", b*b, 4*a*c);
                delta = b*b - 4*a*c;
                printf("Delta = %2.f\n", delta);


                if (delta > 0.0) {  //Delta maior que zero, possui duas raizes
                    printf("\nComo Delta > 0, existem duas raizes reais: \n");
                    printf("\n2) Aplicar formula de bhaskara: \n");
                    printf ("\nFormula para resolucao x= -(b) (+-) raiz2DELTA / 2*a \n");
                    printf ("\nx1 = [-(%.f) + raiz%.f] / [2*%.f]\n", a, delta, b );
                    printf ("x2 = [-(%.f) - raiz%.f] / [2*%.f]\n", a, delta, b );
                    x1 = (-b + sqrt(delta)) / (2.0*a);
                    x2 = (-b - sqrt(delta)) / (2.0*a);

                    printf("\nx1 = %.2f\n", x1);
                    printf("x2 = %.2f\n", x2);
                } else if (delta == 0.0) {
                    x1 = -b / (2.0*a);
                    printf("Uma raiz real dupla: x = %.2f\n", x1); //Se delta for igual a zero. Possui apenas uma raiz.
                } else {
                    printf("Sem raizes reais (Delta < 0).\n"); //Se o valor de delta for menor que zero. Motra que não tem raiz
                }
            }

        } else if (opcao == 3) {
            printf("\nSobre: Programa desenvolvido por: Marco Antonio de Almeida Santos e Mauro Augusto Regis Assad.\n");

        } else if (opcao == 0) {
            printf("Saindo...\n");
            continuar = 0;

        } else {
            printf("Opcao incorreta. Tente novamente.\n");
        }
    }

    return 0;
}


