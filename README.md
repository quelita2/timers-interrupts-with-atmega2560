# Temporizadores e Contadores no ATmega2560

O objetivo dessa vez foi compreender o conceito de temporizadores/contadores em microcontroladores. Para isso, utilizamos o exemplo prático de ligar um LED para explorar e aprender como usá-los no ATmega2560.

>Definição: Um temporizador é um componente eletrônico que gera atrasos de tempo ou realiza a contagem de eventos em intervalos regulares.

Como consequência direta da definição, são utilizados para geração de sinais periódicos e eventos, como também contam pulso de clock interno ou externo.

** Temporizadores/Contadores são importantes em sistemas embarcados por estarem associados com precisão de tempo, controle de sequência, medições temporais e PWM (Modulação por Largura de Pulso). **

## 📦 Components


## 🤖 Settings
- Temporizadores no modo de operação Normal (tabela 16-8 do [DataSheet](docs/Atmega2560_-__Datasheet.pdf)), que é o modo mais simples de operação **TC0 Modo Normal**.
- A habilitação da interrupção é gerada no estouro (overflow). Ocorre estouro quando retorna para 0 e o bit sinalizador de estouro TOV0 é colocado em 1.

    Para utlização do TC0 é necessário a configuração de três registradores:
    - TCCR0A (Modo de configuração)
    - TCCR0B (Configuração de prescaler)
    - TIMSK0 (Habilitação da interrupção)

**Implementação em C:**

    ```c
    #include <avr/io.h>
    #include <avr/interrupt.h>
    #include <util/delay.h>

    int main(void){              
        DDRG = 0b00100000;
        TCCR0A = 0b00000000;
        TCCR0B = 0b00000001;
        TIMSK0 = 0b00000001;
        sei(); 
        
        while(1){ }
        
        return 0;
    }

    ISR(TIMER0_OVF_vect){
        if(PING & 0b00100000){
            PORTG = 0b00000000;
        }else{
            PORTG = 0b00100000;
        }
    }
    ```

    Etapas do código:

    1. Incluir as bibliotecas
    2. Configurar os registradores
    3. Habilitar as interrupções globais
    4. Aplicar o programa principal no loop
    5. Aplicar a rotina de interrupção

## 🔬 Prática Laboratorial

Na prática laboratorial trabalhamos em analisar a geração de sinais por meio do temporizador, no exemplo prático e básico de acender um LED. Veja nossos resultados acessando o [link](https://youtu.be/ZxBM4SYjZ8c).

## ✍️ Authors
- [Ernane Ferreira](https://github.com/ernanej)
- [Quelita Míriam](https://github.com/quelita2)
- [Thiago Lopes](https://github.com/thiagonasmto)