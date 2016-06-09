/* Copyright 2016 - Nathan Sargon Werlich */
template <typename T> /*!< template generico do tipo T*/
#define TamanhoDaLista 100 /*!< valor constante para inicializar array dados*/
#define ERROLISTACHEIA -1  /* Valor para throw Lista Cheita */
#define ERROLISTAVAZIA -2  /* Valor para throw Lista Vazia */
#define ERROPOSICAO -3     /* Valor para throw posição */
//!  Classe para a implementação de uma lista
/*!
 *   \author Nathan Sargon Werlich.
 *   \since 15/04/16
 *   \version 1.0
 */

class Lista {
 private:
    T* dados; /*< Criando um ponteiro */
    int fim; /*< Criando a variavel 'fim' que define o fim da lista */
    int TamanhoLista; /*< Criando a 'tamanho' que define o tamanho da lista */

 public:
    //! Construtor da Lista.
    /*!
     *A variavel 'tamanhoLista' recebe o valor da constante 'TamanhoDaLista'
     *Instancia o vetor dados em Lista e inicia ele com o valor de 'TamanhoLista'
     *Set a variavel 'fim' como -1, essa variavel indica o fim da Lista
     */
	Lista() {
	    TamanhoLista = TamanhoDaLista;
        dados = new T[TamanhoLista];
        fim = -1;
    }
    //! Construtor explicito da Lista.
    /*!
     *A variavel 'TamanhoLista' recebe o valor do parametro 'tam'
     *Instancia o vetor dados em Lista e inicia ele com o valor de 'TamanhoLista'
     *Set a variavel 'fim' como -1, essa variavel indica o fim da Lista
     */
	explicit Lista(int tam) {
	    TamanhoLista = tam;
	    dados = new T[TamanhoLista];
	    fim = -1;
    }
    /*
     * @brief Metodo para adicionar um elemento na Lista
     * @details Caso exista lugar na lista, incrementa a variavel 'fim' e adiciona o parametro
     * 'dado' no vetor 'dados[]' na posição 'fim'
     */
	void adiciona(T dado) {
	    if (listaCheia()) {
	        throw(ERROLISTACHEIA);
        } else {
            fim += 1;
            dados[fim] = dado;
        }
	}
	/*
     * @brief Metodo para adicionar um elemento no inicio da Lista
     * @details Cria uma variavel de inteiros auxiliar chamada 'pos' e verifica se a lista já não está cheia
     * Caso ainda exista lugar na lista passa todos os elementos do vetor uma posição para frente e 
     * adiciona o o parametro 'dado' na posição '0' do vetor 'dados[]'
     */
	void adicionaNoInicio(T dado) {
	    int pos;
	    if (listaCheia()) {
	        throw(ERROLISTACHEIA);
	    } else {
	        fim += 1;
	        pos = fim;
	        while (pos > 0) {
            dados[pos] = dados[pos-1];
	        pos -= 1;
	        }
	        dados[0] = dado;
	    }
	}
	/*
     * @brief Metodo para adicionar um dado numa determinada posição do vetor
     * @details Verifica se a lista não está cheia ou se a posição passada pelo paramentro 'posicao' está dentro dos limites da Lista
     * Cria uma variavel auxiliar de inteiros chamada 'pos'
     * Joga todos os elementos da lista até 'posicao' uma posição a frente no vetor e apos isso
     * Adicion o parametro 'dado' na posição passada pelo parametro 'posicao'
     */
	void adicionaNaPosicao(T dado, int posicao) {
	    int pos;
	    if (listaCheia()) {
	        throw(ERROLISTACHEIA);
	    } else {
	        if (posicao > fim+1 || posicao < 0) {
	            throw(ERROPOSICAO);
	        }
	        fim += 1;
	        pos = fim;
	        while (pos > posicao) {
	            dados[pos] = dados[pos-1];
	            pos -= 1;
	        }
        dados[posicao] = dado;
	    }
	}
	/*
     * @brief Metodo adicionar elementos em ordem no vetor
     * @details Verifica se a lista não está Cheia
     * Cria uma variavel auxiliar de inteiros chamada 'pos'
     * Faz comparações dos parametros 'dado' e 'dados[pos]' atraves do metodo 'maior()'
     * Retorna o metodo 'adicionaNaPosicao()' e passa como parametros 'dado' e a variavel 'pos'
     */
	void adicionaEmOrdem(T dado) {
	    int pos;
	    if (listaCheia()) {
	        throw(ERROLISTACHEIA);
	    } else {
	        pos = 0;
	        while (pos < fim && maior(dado, dados[pos])) {
                pos += 1;
	        }
	        return (adicionaNaPosicao(dado, pos));
        }
	}
	/*
     * @brief Metodo para retirar elementos do vetor
     * @details Verifica se a lista não está Vazia
     * Decrementa a variavel 'fim' e retorna o vetor 'dados[]' com a posição 'fim +1'
     */
	T retira() {
	    if (listaVazia()) {
	        throw(ERROLISTAVAZIA);
        } else {
            fim -= 1;
            return (dados[fim+1]);
        }
	}
    /*
     * @brief Metodo para retirar um elemento do inicio do vetor
     * @details Verifica se a lista não está Vazia
     * Cria duas variaveis auxiliares de inteiros chamadas 'pos' e 'valor'
     * Traz todos os elementos do vetor uma posição para frente e retorna
     * a informação que estava na posição zero do vetor 'dados[]'
     */
	T retiraDoInicio() {
	    int pos, valor;
	    if (listaVazia()) {
	        throw(ERROLISTAVAZIA);
	    } else {
            fim -= 1;
            valor = dados[0];
            pos = 0;
            while (pos <= fim) {
                dados[pos] = dados[pos+1];
                pos += 1;
            }
        return (valor);
        }
	}
	/*
     * @brief Metodo para retirar um dado de uma posição expecifica da Lista
     * @details Verifica se a posição existe na Lista, caso não exista retorna um throw
     * Cria duas variaveis auxiliares de inteiros chamada 'pos' e 'valor'
     * Verifica se a Lista não está Vazia, caso esteja retorna um throw
     * Joga todos os elementos apos o parametro 'posicao' uma posição para traz
     * Retorna o dado do vetor 'dados[]' na posição 'posicao'
     */
	T retiraDaPosicao(int posicao) {
	    int pos, valor;
	    if (posicao > fim || posicao < 0) {
	        throw(ERROPOSICAO);
        } else {
            if (listaVazia()) {
                throw(ERROLISTAVAZIA);
            } else {
                fim -= 1;
                valor = dados[posicao];
                pos = posicao;
                while (pos <= fim) {
                    dados[pos] = dados[pos+1];
                    pos += 1;
                }
                return (valor);
            }
        }
	}
	/*
     * @brief Metodo para retirar um dado especifico da Lista
     * @details Verifica se a lista não está vazia, caso esteja retorna um throw.
     * Cria uma variavel auxiliar de inteiro chamada 'pos' e chama o metedo 'posicao' 
     * para atribuir a posição no array 'dados[]' do elemento 'dado'.
     * Verifica se a variavel 'pos' tem um valor valido, ou seja maior que zero, caso
     * isso se confirme retorna o metodo 'retiraDaPosicao' e passa como parametro a variavel 'pos'
     */
	T retiraEspecifico(T dado) {
	    int pos;
	    if (listaVazia()) {
	        throw(ERROLISTAVAZIA);
	    } else {
	        pos = posicao(dado);
	        if (pos < 0) {
	            throw(ERROPOSICAO);
	        } else {
	            return (retiraDaPosicao(pos));
	        }
	    }
	}
	/*
     * @brief Metodo pegar a posição de um elemento da Lista
     * @details Cria uma variavel auxiliar chamada 'pos', apos isso é feito um laço de repetição que
     * verifica se ainda não chegamos ao fim da lista e chama o metodo 'igual' para verificar
     * se a posição do parametro 'dado' ja foi encontrada.
     * Apos isso é verificado se a posição encontrada é valida, ou seja, se o dado na varival 'pos' é menor ou igual a variavel 'fim'
     */
	int posicao(T dado) {
	    int pos = 0;
        while (pos <= fim && !(igual(dado, dados[pos]))) {
            pos += 1;
        }
        if (pos > fim) {
            throw(ERROPOSICAO);
        } else {
            return (pos);
        }
	}
	/*
     * @brief Metodo para ver se determinado dado esta presente na Lista
     * @details Verifica se a lista esta vazia, tenha alguma informação na lista
     * é iniciado um 'FOR' para comparar a variavel 'dado' que é passada como parametro
     * e o array 'dados[]', caso ache tenha uma comparação positiva é retornado verdadeiro
     */
	bool contem(T dado) {
	    if (listaVazia()) {
	        return false;
        }
	    for (int i = 0; i < fim + 1; i++)
            if (dado == dados[i]) {
                return true;
            }
	    return false;
    }
    /*
     * @brief Metodo para comparar o tamanho de dois dados da Lista
     * @details Retorna verdadeiro caso a variavel 'dado1' igual a variavel 'dado2'
     */
	bool igual(T dado1, T dado2) {
	    if ((dado1 == dado2)) {
	        return (true);
	    } else {
	        return (false);
        }
	}
	/*
     * @brief Metodo para comparar o tamanho de dois dados da Lista
     * @details Retorna verdadeiro caso a variavel 'dado1' for maior que a variavel 'dado2'
     */
	bool maior(T dado1, T dado2) {
	    if (dado1 > dado2) {
	        return (true);
	    } else {
	        return (false);
        }
	}
	/*
     * @brief Metodo para comparar o tamanho de dois dados da Lista
     * @details Retorna verdadeiro caso a variavel 'dado1' for menor que a variavel 'dado2'
     */
	bool menor(T dado1, T dado2) {
	    if (dado1 < dado2) {
	        return (true);
	    } else {
	        return (false);
	    }
	}
	/*
     * @brief Metodo que avisa se a Lista está cheia
     * @details Retorna verdadeiro caso a variavel 'fim' for igual variavel 'TamanhoLista -1'
     */
	bool listaCheia() {
	    if ((fim == TamanhoLista-1)) {
    	    return (true);
    	} else {
    	    return (false);
        }
	}
    /*
     * @brief Metodo que avisa se a Lista está vazia
     * @details Retorna verdadeiro caso a variavel 'fim' for igual '-1'
     */
	bool listaVazia() {
	    if ((fim == -1)) {
	        return (true);
        } else {
            return (false);
        }
    }
    /*
     * @brief Metodo para destruir a Lista
     * @details Atribui '-1' a variavel fim
     */
	void destroiLista() {
	    fim = -1;
    }
};
