# Cache Simulator

Este programa é baseado no sim-cache e simula o comportamento de uma memória cache, dado um arquivo binário de entrada com os endereços.

Utilização:

```cache_simulator <nsets> <bsize> <assoc> <substituição> <flag_saida> <arquivo_de_entrada> <debug_mode_flag>```

Onde: 
- \<nsets> é o número de conjuntos
- \<bsize> é o tamanho do bloco (em bytes)
- \<assoc> é o grau de associatividade
- \<substituição> é a política de substituição. Existem 3 políticas de substituição:
  - f - FIFO
  - l - LRU
  - r - Random 
- \<flag_saida> indica se a saída será a saída resumida (padrão - 1) ou a saída detalhada (verbosa - 0).
- arquivo_de_entrada.bin é o _path_ do arquivo contendo os endereços. **Esse arquivo deve estar em Big Endian**.
- \<debug_mode_flag> [OPCIONAL] habilita informações de debug na execução do programa. Este valor pode ser 0 (desabilitado) ou 1 (habilitado). Se não for informado, assume-se 0.
