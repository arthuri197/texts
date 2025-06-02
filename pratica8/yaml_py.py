"""
Programa: Parsing e pré-processamento de arquivo YAML para NLP

Autor:  Arthur Oliveira
Data: 02/06/2025

Descrição:
    Script Python que abre um arquivo YAML contendo documentos,
    carrega seu conteúdo estruturado, pré-processa os textos removendo pontuação e 
    convertendo para minúsculas, e prepara os dados para uso em Processamento de Linguagem Natural (PLN).
    Ao final, imprime os dados processados no console.

License: CC BY
"""

import yaml  # Biblioteca para manipular arquivos YAML
import re    # Biblioteca para expressões regulares (usada na limpeza de texto)

def carregar_arquivo_yaml(caminho):
    """
    Abre e carrega o conteúdo do arquivo YAML especificado pelo caminho.
    Retorna os dados convertidos para estruturas Python (dicionários e listas).
    """
    with open(caminho, 'r', encoding='utf-8') as f:
        return yaml.safe_load(f)

def preprocessar_texto(texto):
    """
    Realiza pré-processamento básico no texto:
    - converte para minúsculas
    - remove pontuação
    - normaliza espaços em branco
    Retorna o texto limpo pronto para análise.
    """
    texto = texto.lower()
    texto = re.sub(r'[^\w\s]', '', texto)  # Remove caracteres que não são letras, números ou espaço
    texto = re.sub(r'\s+', ' ', texto)     # Substitui múltiplos espaços por um espaço único
    return texto.strip()                    # Remove espaços em branco no início e fim

def preparar_corpus(dados):
    """
    Recebe dados carregados do YAML e converte para uma lista de documentos formatados para NLP.
    Cada documento contém:
      - id
      - título
      - texto pré-processado
      - categorias
    Retorna a lista de documentos processados.
    """
    corpus = []
    for doc in dados['documentos']:
        texto_processado = preprocessar_texto(doc['texto'])
        corpus.append({
            'id': doc['id'],
            'titulo': doc['titulo'],
            'texto': texto_processado,
            'categorias': doc['categorias']
        })
    return corpus

if __name__ == "__main__":
    # Carrega os dados do arquivo YAML
    dados = carregar_arquivo_yaml('documentos.yaml')

    # Processa os textos para preparar o corpus para PLN
    corpus = preparar_corpus(dados)

    # Imprime o resultado no console para conferência
    for doc in corpus:
        print(f"ID: {doc['id']}")
        print(f"Título: {doc['titulo']}")
        print(f"Texto processado: {doc['texto']}")
        print(f"Categorias: {', '.join(doc['categorias'])}")
        print("-" * 40)
