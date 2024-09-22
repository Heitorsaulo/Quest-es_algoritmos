#/bin/bash
gcc plantacaoOtima.c -o plantacaoOtima -lm
gcc gerarCasosTeste.c -o gen

for i in 1 2 3 4 5;
do
  ./gen > casos_teste/"$i".in
  ./plantacaoOtima < casos_teste/"$i".in > casos_teste/"$i".out
  sleep 1
done