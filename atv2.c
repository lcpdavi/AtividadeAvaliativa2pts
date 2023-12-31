#include <stdio.h>
#include <string.h>

// Validar sexo
char* validarSexo(){
    static char sexo[10];
    do{
        fflush(stdin);
        printf("Informe o sexo - Masculino ou Feminino:\n");
        fgets(sexo, sizeof(sexo), stdin);
        sexo[strcspn(sexo, "\n")] = '\0';
    }while(strcmp(sexo, "Masculino") != 0 && strcmp(sexo, "Feminino") != 0);

    return sexo;
}

// Validar salario
float validaSalario(){
    float salario;
    do{
        printf("Informe o salario:\n");
        scanf("%f", &salario);
    }while(salario <= 1.00);
    return salario;
}

// Salario ao salario minimo
char* classificarSalario(float salario){
    const float salarioMinimo = 1400.00;
    if(salario > salarioMinimo){
        return "Acima do salario minimo";
    }else if (salario < salarioMinimo) {
        return "Abaixo do salario minimo";
    }else {
        return "Igual ao salario minimo";
    }
}

void mostraClassificacao(char* sexo, float salario){
    printf("Salario: R$%.2f\n", salario);
    printf("Classificacao: %s\n", classificarSalario(salario));
    printf("Sexo: %s\n", sexo);
    printf("\n");
}

int main(){
    int numAssalariados, abaixoSalarioMinimo = 0, acimaSalarioMinimo = 0;

    printf("Informe o numero de assalariados:\n");
    scanf("%d", &numAssalariados);

    for(int i = 0; i < numAssalariados; i++){
        printf("\nAssalariado %d:\n", i + 1);

        char* sexo = validarSexo();
        float salario = validaSalario();

        // Quantidade de assalariados abaixo ou acima do salario minimo
        if(salario < 1400.00){
            abaixoSalarioMinimo++;
        }else if (salario > 1400.00){
            acimaSalarioMinimo++;
        }

        // Mostra os resultados
        mostraClassificacao(sexo, salario);
    }

    // Total de assalariados abaixo e acima do salario minimo
    printf("Total de assalariados abaixo do salario minimo: %d\n", abaixoSalarioMinimo);
    printf("Total de assalariados acima do salario minimo: %d\n", acimaSalarioMinimo);

    return 0;
}