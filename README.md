# projeto_compressor_de_imagens
Trabalho - Projeto de Compressor de Imagens em Linguagem C | Professor Daniel | Ciências da Computação

### 👥 Equipe
Miguel Arcanjo |
Thyago da Silva |
Thierry Cavalcante |
Rodrigo Fernandes

# 🖼️ Projeto de Compressor de Imagens em Linguagem C | Prof° Daniel Ferreira

## 🚀 Começando

Com este guia, você poderá preparar o projeto no seu computador, fazer a compilação, rodar tanto o codificador quanto o decodificador, e testar a linha de compressão inteira.

Para saber como usar, consulte a parte que fala sobre a Implantação.

### 🧰 Pré-requisitos

1. 🛠️ Compilador GCC (Usado no Projeto)
2. 💻 Terminal Linux ou Powershell
3. 🖼️ Arquivos de imagens .PGM
4. 🧪 Ferramentas para visualização de imagens (ex.: GIMP)

### 📥 Instalação Inicial

1. Clonar o repositório no Terminal para instalar o repositório Git
```
git clone https://github.com/rodrigofern96/projeto_compressor_de_imagens
```
2. cd projeto_compressor_de_imagens

### ⚙️ Compilando Codificador
1. Acessar o repositório /CodPreOrdem no Terminal
2. No terminal, escreva o comando "make" ("mingw32-make" se estiver usando Windows) para estar executando o makefile
```   
make
```

### 🔧 Compilando Decodificador
1. Acessar o repositório /DecPreOrdem no Terminal
2. No terminal, escreva o comando "make" para estar executando o makefile
```
make
```  

## 🧪 Executando os testes 


### 🔼 Executando Codificador

1. Entre na pasta do codificador
2. Execute o seguinte comando mudando apenas os parâmetros

```
./cod <imagem_entrada.pgm> <bitstream.dp> <taxadeCompressão> 
``` 

## Exemplo:
```
./cod img01.pgm bitstreamNOME.dp 8
```

📌 Obs: Entre com o nome do bitstream a ser criado

### 🚀 Executando Decodificador

1. Entre na pasta do decodificador
2. Execute o seguinte comando mudando apenas os parâmetros

``` 
./dec <bitstream.dp> <imagem_saida.pgm> 
``` 

## Exemplo:

```
./dec bitstreamNOME.dp img02.pgm
```

📌 Obs: Entre com bitstream gerado pelo codificador

## 📦 Implantação

1. 🗜️ Codificador
2. 🔄 Decodificador
3. 🖼️ Imagem PGM imagem_entrada.pgm
