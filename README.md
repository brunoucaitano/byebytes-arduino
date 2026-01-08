# ☀️ ByeBytes - Automação Sustentável para Forno Solar

[cite_start]O **ByeBytes** é uma solução que integra tecnologia e sustentabilidade para otimizar o preparo de alimentos via energia solar[cite: 226, 227]. [cite_start]Através de um sistema baseado em **Arduino**, o projeto automatiza o monitoramento da luz e o tempo de cozimento[cite: 232].

## 🛠️ Hardware e Conexões
Com base no código implementado, a montagem segue esta pinagem:

| Componente | Pino | Função |
| :--- | :--- | :--- |
| **LED 1** | D2 | Indica se há luz solar suficiente (LDR > 500) |
| **LED 2** | D3 | Indica a seleção do Timer (Pisca 1, 2 ou 3 vezes) |
| **LED 3** | D4 | Indica que o forno está em funcionamento |
| **Botão 1** | D5 | Selecionador de tempo (5, 15 ou 30 min) |
| **Botão 2** | D6 | Inicia a contagem de tempo |
| **LDR** | A0 | Sensor de luminosidade para eficiência térmica |

## 💡 Lógica de Funcionamento
1. **Monitoramento Solar:** O sistema utiliza um LDR para verificar a incidência de luz em tempo real.
2. **Seleção de Ciclo:** O usuário escolhe o tempo de exposição através de botões físicos.
3. **Automação de Cozimento:** Ao iniciar, o sistema gerencia o tempo via software (`millis`), mantendo o monitoramento visual do processo.

---
[cite_start]**Projeto desenvolvido por:** Bruno Caitano Alves [cite: 225]
