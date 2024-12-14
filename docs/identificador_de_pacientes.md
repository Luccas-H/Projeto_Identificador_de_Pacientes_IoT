# Plano de Testes - Sistema de Identificação de Pacientes com RFID

## 1. Introdução

### Objetivo
Este documento define o plano de teste e os casos de teste para o **Sistema de Identificação de Pacientes com RFID**, com o intuito de verificar a funcionalidade, desempenho e confiabilidade do sistema.

### Escopo
Os testes cobrem os principais componentes e funcionalidades do sistema, incluindo:
- Leitura de cartões RFID.
- Exibição de mensagens no LCD.
- Resposta do sistema a cartões autorizados e não autorizados.
- Tempo de resposta para identificação de cartões.

---

## 2. Estratégia de Teste

### Metodologia
Os testes serão realizados manualmente, com foco nos seguintes tipos:
- **Funcionais**: Verificação de leitura de cartões RFID e mensagens no LCD.
- **Desempenho**: Teste do tempo de resposta ao passar os cartões.
- **Confiabilidade**: Teste da capacidade de recuperação em caso de erros.

### Ambiente de Teste
- **Dispositivo Utilizado**: Arduino Mega.
- **Componentes**: Módulo PN532, LCD 16x2.
- **Ferramentas**: Arduino IDE para programação e monitor serial para depuração.

### Responsáveis pelo Teste
- **Equipe**: Ranier Veras e Matheus Lima.
- **Testador Designado**: Matheus Lima.

---

## 3. Casos de Teste

### Caso de Teste 1: Leitura de Cartão RFID Autorizado
- **ID**: CT-001
- **Descrição**: Validar se o sistema reconhece corretamente um cartão autorizado.
- **Pré-condição**: Um cartão com o UID autorizado está disponível e configurado no sistema.
- **Passos de Teste**:
  1. Ligar o Arduino Mega.
  2. Aproximar o cartão autorizado do módulo PN532.
  3. Observar o LCD para verificar a mensagem exibida.
- **Resultado Esperado**: O LCD deve exibir "Acesso Autorizado" dentro de 1 segundo após a leitura.
- **Resultado Real**: Aproximado a TAG com mesmo UID cadastrado no sistema, mostrou-se na tela LCD "Acesso Autorizado".
- **Status**: Passou.
[Teste 1 - Acesso autorizado](../images/TesteAcessoAutorizado.jpeg)
---

### Caso de Teste 2: Leitura de Cartão RFID Não Autorizado
- **ID**: CT-002
- **Descrição**: Verificar se o sistema nega o acesso para cartões não autorizados.
- **Pré-condição**: Um cartão com UID não configurado está disponível.
- **Passos de Teste**:
  1. Ligar o Arduino Mega.
  2. Aproximar o cartão não autorizado do módulo PN532.
  3. Observar o LCD para verificar a mensagem exibida.
- **Resultado Esperado**: O LCD deve exibir "Acesso Negado" dentro de 1 segundo após a leitura.
- **Resultado Real**: Após passar o cartão com UID diferente, moutrou-se na tela LCD "Acesso Negado".
- **Status**: Passou.
[Teste 2 - Acesso negado](../images/TesteAcessoNegado.jpeg)

---

### Caso de Teste 3: Tempo de Resposta ao Passar o Cartão
- **ID**: CT-003
- **Descrição**: Validar o tempo de resposta do sistema ao identificar cartões autorizados e não autorizados.
- **Pré-condição**: Um cartão (autorizado ou não autorizado) está disponível.
- **Passos de Teste**:
  1. Ligar o Arduino Mega.
  2. Passar o cartão no módulo PN532.
  3. Medir o tempo entre a aproximação do cartão e a exibição da mensagem no LCD.
- **Resultado Esperado**: O tempo de resposta não deve exceder 1 segundo.
- **Resultado Real**: Aproximando-se a TAG de maneira a entrar no campo do sensor, o circuito protamente exibiu a mensagem do LCD rapidamente.
- **Status**: Passou.

---

### Caso de Teste 4: Recuperação de Erros
- **ID**: CT-005
- **Descrição**: Validar se o sistema retorna ao estado de espera após erros.
- **Pré-condição**: Um cartão não autorizado é passado e o sistema está funcionando corretamente.
- **Passos de Teste**:
  1. Ligar o Arduino Mega.
  2. Passar um cartão não autorizado.
  3. Verificar a mensagem exibida no LCD.
  4. Aguardar 3 segundos e verificar se o sistema retorna à mensagem "Waiting for card...".
- **Resultado Esperado**: O LCD deve retornar para "Waiting for card..." após a exibição de "Acesso Negado".
- **Resultado Real**: Após negar o acesso, o código prontamente identificou que estava esperando o UID correto, logo no LCD mostrou "Waiting for card...".
- **Status**: Passou.
[Teste 4 - Esperando cartao](../images/TesteEsperandoCartao.jpeg)
---

## 4. Critérios de Aprovação

1. **Funcionalidade**:
   - Todos os cartões autorizados devem ser reconhecidos corretamente.
   - Cartões não autorizados ou passados rápido demais devem exibir "Acesso Negado".

2. **Desempenho**:
   - O tempo de resposta deve ser inferior a 1 segundo.

3. **Resiliência**:
   - O sistema deve retornar ao estado de espera após qualquer erro ou interação.

4. **Confiabilidade**:
   - O sistema deve ser capaz de ler múltiplos cartões consecutivos sem falhas.

---

## 5. Conclusão

### Resumo dos Resultados
O circuito respondeu prontamente a todos os itens de maneira esperada, sendo aprovado com êxito para utilização efetiva. 

### Recomendações 
Utilização de uma antena ou sensor que possa aumentar o campo de captura da TAG com UID correta e integração com banco de dados para identificação correta dos pacientes, não sendo necessário configurar cada um.  
