# Métodos Numéricos - Implementação do Livro *Cálculo Numérico*

Este repositório contém implementações dos métodos numéricos apresentados no livro *Cálculo Numérico* de Márcia A. Gomes Ruggiero.

## Métodos para Encontrar Raízes

Os seguintes métodos foram implementados:

1. [**Bisseção**](https://github.com/alvaro52/metodos-numericos-I/blob/main/src/root_finding/root_finding.cpp#L5-L32)
2. [**Falsa Posição**](https://github.com/alvaro52/metodos-numericos-I/blob/main/src/root_finding/root_finding.cpp#L34-L62)
3. [**Newton-Raphson**](https://github.com/alvaro52/metodos-numericos-I/blob/main/src/root_finding/root_finding.cpp#L64-L83)
4. [**Secante**](https://github.com/alvaro52/metodos-numericos-I/blob/main/src/root_finding/root_finding.cpp#L85-L109)
5. [**Ponto Fixo**](https://github.com/alvaro52/metodos-numericos-I/blob/main/src/root_finding/root_finding.cpp#L111-L129)

## Métodos para Resolver Sistemas Lineares

Os seguintes métodos foram implementados para resolver sistemas lineares:

1. [**Eliminação de Gauss**](https://github.com/alvaro52/metodos-numericos-I/blob/main/src/linear_systems_solver/gauss_elimination.cpp)
2. [**Eliminação de Gauss-Jordan**](https://github.com/alvaro52/metodos-numericos-I/blob/main/src/linear_systems_solver/gauss_jordan.cpp)
3. [**Método de Gauss-Jacobi**](https://github.com/alvaro52/metodos-numericos-I/blob/main/src/linear_systems_solver/gauss_jacobi.cpp)
4. [**Método de Gauss-Seidel**](https://github.com/alvaro52/metodos-numericos-I/blob/main/src/linear_systems_solver/gauss_seidel.cpp)
5. [**Decomposição LU**](https://github.com/alvaro52/metodos-numericos-I/blob/main/src/linear_systems_solver/lu_factorization.cpp)  

## Estrutura do Repositório


## Como Compilar e Executar

Este projeto utiliza CMake para gerenciar o processo de compilação. Siga as instruções abaixo:

1. **Clone o repositório**:
   ```bash
   git clone https://github.com/alvaro52/metodos-numericos-I.git
   cd metodos-numericos-I
   ```
2. **Crie um diretório de compilação**:
   ```bash
   mkdir build
   cd build
   ```
3. **Configure o projeto com CMake**:
   ```bash
    cmake ..
    ```
4. **Compile o projeto**:
   ```bash
   cmake --build .
   ```
5. **Execute o projeto**:
   ```bash
    ./Debug/numerical_methods_I
    ```