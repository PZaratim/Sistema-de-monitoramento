Sistema de Monitoramento de Cruzamento com Dois Sensores

Descrição:
O Sistema de Monitoramento de Cruzamento é um projeto desenvolvido para gerenciar a prioridade de tráfego em um cruzamento usando apenas dois sensores de presença de veículos.
O foco do projeto é demonstrar a lógica de contagem e tomada de decisão para determinar qual via deve ter prioridade, servindo como base para aplicações em sistemas inteligentes de semáforos.
O sistema foi implementado em C utilizando FreeRTOS, sendo ideal para aprendizado de IoT, sistemas embarcados e automação de tráfego.

Funcionalidades:
Contagem de veículos em duas vias distintas usando dois sensores.
Evita contagens múltiplas para o mesmo veículo, garantindo precisão.
Determina automaticamente a prioridade da via com maior número de veículos.
Pequeno delay para reduzir uso da CPU e garantir estabilidade do sistema.

Estrutura do Sistema:
Sensores de presença – detectam veículos nas duas vias do cruzamento.
Contadores de veículos – armazenam o número de carros detectados em cada via.
Módulo de decisão – compara os contadores e determina qual via deve ter prioridade.

Lógica do Código:
 Função de contagem
  Lê o sensor correspondente
  Incrementa o contador se detectar veículo
  Aguarda até o sensor ficar inativo para evitar contagem duplicada
 Função de decisão
   Compara os contadores de veículos
   Define e exibe qual via possui prioridade
 Loop principal
   Executa a contagem e decisão continuamente
   Adiciona pequeno delay para estabilidade do sistema
