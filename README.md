Raspberry Pi Pico W e PWM

Este projeto implementa o controle de um servomotor usando o Raspberry Pi Pico W e PWM, simulando no Wokwi.
Tambem controla a intensidade da luminosidade de um LED

## 📌 Requisitos
- *Hardware*: Simulado no Wokwi
- *Software*:
  - [VS Code](https://code.visualstudio.com/)
  - [Pico SDK](https://github.com/raspberrypi/pico-sdk)
  - [Wokwi](https://wokwi.com/)
  - [GitHub](https://github.com/)

## 🛠️ Configuração do Ambiente
1. Instale o *Pico SDK* e configure no VS Code.
2. Clone este repositório:
   ```bash
   git clone https://github.com/seu-usuario/nome-do-repositorio.git
   cd nome-do-repositorio

3. Compile e carregue o código no Wokwi.



📜 Código-Fonte

O código está no arquivo main.c e utiliza PWM na GPIO 22 para controlar o ângulo do servomotor.

🔧 Funcionamento

1. Define frequência PWM de 50Hz.


2. Posiciona o servo em 180°, 90° e 0° com pausas de 5s.


3. Implementa movimento suave entre 0° e 180° com passos de 5µs.


4. Aciona o LED RGB na GPIO 12 durante o experimento.



📂 Estrutura do Projeto

├── src/
│   ├── main.c
│   ├── CMakeLists.txt
├── wokwi/
│   ├── diagram.json
├── README.md

🎥 Demonstração

Confira a execução do código no vídeo abaixo:
🔗 Link para o vídeo

📌 Como Rodar no Wokwi

1. Abra o Wokwi.


2. Importe o arquivo diagram.json.


3. Carregue e rode o código.