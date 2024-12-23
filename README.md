# Perguntrilha
![Projeto Finalizado](https://img.shields.io/badge/Status-Finalizado-brightgreen)
![Licença Não Comercial](https://img.shields.io/badge/Licen%C3%A7a-N%C3%A3o--Comercial-red)

O **Perguntrilha** é um jogo interativo e educativo desenvolvido a partir da combinação de dois jogos amplamente conhecidos: o **labirinto elétrico** e os tradicionais **quizzes de perguntas e respostas**, para a **ProjETE 2K23**, uma feira de projetos tecnológicos realizada anualmente pela **ETE FMC**, a primeira escola técnica da América Latina.  
O projeto foi criado para tornar o aprendizado e o desenvolvimento da coordenação mais envolventes para crianças do ensino fundamental, combinando diversão e educação. Dessa forma, o projeto, que incentiva a colaboração em grupo ou o desafio individual, busca despertar a curiosidade e o gosto pelo conhecimento desde cedo, transformando o estudo em uma experiência prazerosa e motivadora.

---

## Funcionamento do projeto

O **Perguntrilha** funciona a partir de um trilho metálico alimentado com 5V como percurso principal, no qual o jogador conduz uma haste com uma argola metálica com um ímã na ponta, que está está conectada ao Arduino Mega, que monitora digitalmente quantas vezes ela encostou no trilho.
Basicamente, o jogador deve ativar cada um dos oito reed switches estrategicamente posicionados ao longo do caminho para finalizar o jogo, ao mesmo tempo em que precisa evitar encostar no trilho e terminar a partida o quanto antes. 
Cada ativação desses sensores é registrada pelo Arduino Mega, que randomiza um número de 1 a 50 associado a uma pergunta com cinco alternativas, distribuída entre quatro níveis de dificuldade, totalizando 200 perguntas, que devem ser respondidas pelo jogador por meio dos botões correspondentes no painel do jogo em um tempo limite de três minutos, monitorado pelo microcontrolador do projeto.
O jogo termina se o tempo acabar ou se todas as perguntas forem respondidas, enquanto a pontuação final é calculada com base no número de perguntas respondidas corretamente, no tempo total utilizado e na quantidade de vezes que o jogador encostou no trilho, promovendo um equilíbrio entre habilidade, rapidez e raciocínio lógico.

Para saber mais sobre o projeto, acesse o link do diário de bordo do Perguntrilha, documento desenvolvido ao longo de todo o processo de desenvolvimento do projeto pela equipe com fotos, vídeos, arquivos e versões dos códigos utilizados.
- [Diário de Bordo](https://eteacojeorg-my.sharepoint.com/:o:/g/personal/kaua_ribeiro_edu_etefmc_com_br/EtEPDnoMw_VPvIZYPMDQiwQBfv8gBG_IYea85vz6bszALw?e=wREcEo)

---

## Tecnologias Utilizadas

### Software:
- Linguagem de Programação: C++

### Hardware:
- Processamento: Arduino Mega
- Sensoriamento: Reed Switches

---

## Fundadores

- **Fellipe Borsato**  
  [GitHub](https://github.com/Fellipe-Borsato) 
- **Lucas Mendonça**  
- **Kauã Ribeiro** - Líder  
  [LinkedIn](https://www.linkedin.com/in/kaua-ribeiro17/) | [GitHub](https://github.com/Kauakim)  
- **Luiz Fernando**  
- **Nycolas Rodrigues**  

---

**Agradecimentos**  
O projeto contou com o apoio crucial da **ETE-FMC**, com orientação do professor **José Manoel**.
