/* Copyright 2016 - Nathan Sargon Werlich */
#include "Elemento.hpp" /*!< inclui o arquivo Elemento.hpp */
template<typename T> /*!< template generico do tipo T*/
// Classe para a implementação de uma Lista Encadeada
/*!
 *   \author Nathan Sargon Werlich.
 *   \since 22/04/16
 *   \version 1.0
 */
class ListaEnc {
 protected:
	Elemento<T>* cabeca; /*< Criando um ponteiro para ser a cabeca da lista*/
	int tamanho; /*< Variavel que indica qual o tamanho atual da lista */

 public:
    //! Construtor da Classe ListaEnc
    /*!
     * A variavel 'tamanho' recebe o tamanho atual da lista, ou seja, '0'
     * O ponteiro 'cabeca' recebe 'NULL'
     */
	ListaEnc() {
        tamanho = 0;
        cabeca = NULL;
	}
	//! Destrutor
    /*!
     * Destrutor da classe ListaEnc. 
     * A variavel 'tamanho' passa a valer '0'
     * É chamado o metodo 'destroiLista()' para eliminar a lista por completo
    */
	~ListaEnc() {
	    tamanho = 0;
	    destroiLista();
	}
    /*
     * @brief Metodo adicionaNoInico
     * @details Metodo para adicionar um elemento no inicio da Lista
     * @param O parametro 'dado' é o elemento a ser adicionado no inicio da Lista
     * É Criado um ponteiro chamado 'novo' e é passado como parametro desse panteiro 'dado' e 'cabeca'
     */
	void adicionaNoInicio(const T& dado) {
	    Elemento<T> *novo = new Elemento<T>(dado, cabeca);
	    if (novo == NULL) {
	        throw("Lista Cheia");
	    } else {
            cabeca = novo;
	        tamanho += 1;
        }
	}
    /*
     * @brief Metodo retiraDoInicio
     * @details Metodo para retirar um elemento do inicio da Lista e libera o endereço de memória que estava sendo usado pelo elemento
     * Cria um ponteiro auxiliar chamado 'saiu'
     * Cria uma varaivel auxiliar chamada 'volta'
     * @return Retorna o elemento retirado que esta contido na varaivel 'volta'
     */
	T retiraDoInicio() {
        Elemento<T> *saiu;
        T volta;
        if (listaVazia()) {
            throw("Lista vazia");
        } else {
            saiu = cabeca;
            volta = saiu->getInfo();
            cabeca = saiu->getProximo();
            delete (saiu);
            tamanho -= 1;
            return (volta);
        }
	}
    /*
     * @brief Metodo eliminaDoInicio
     * @details Metodo para eliminar um elemento do inicio da Lista e libera o endereço de memória que estava sendo usado pelo elemento
     * Cria um ponteiro auxiliar chamado 'saiu'
     */
	void eliminaDoInicio() {
	    Elemento<T> *saiu;
	    if (listaVazia()) {
	        throw("Erro Lista Vazia");
	    } else {
	        saiu = cabeca;
	        cabeca = saiu->setProximo;
	        tamanho -= 1;
	        delete(saiu->getInfo);
	        delete(saiu);
	        return (tamanho);
	    }
	}
    /*
     * @brief Metodo adicionaNaPosicao
     * @details Metodo para adicionar em uma posição especifica
     * @param O parametro 'dado' é o dado a ser alocado em determinada posição
     * @poram O parametro 'pos' é a posição que o dado será adicionado
     * Verifica se a posição é valida
     * Verifica se a posição é '0', caso seja, chama o metodo adicionaNoInicio e passa como parametro 'dado'
     * Cria dois ponteiros auxiliares chamados 'novo' e 'anterior'
     */
	void adicionaNaPosicao(const T& dado, int pos) {
        if (pos < 0 || pos > tamanho) {
            throw("ERRO DE POSICAO");
        } else if (pos == 0) {
            adicionaNoInicio(dado);
        } else {
            Elemento<T> *novo, *anterior;
            novo = cabeca;
            int posi = 0;
            while (posi < pos-1) {
                novo = novo->getProximo();
                posi += 1;
            }
            anterior = novo->getProximo();
            novo->setProximo(new Elemento<T>(dado, anterior));
            tamanho += 1;
        }
	}
    /*
     * @brief Metodo posicao
     * @details Metodo que indica a posição de um elemento contido na Lista
     * @param O parametro 'dado' é o elemento a ter sua posição encontrada
     * É criado uma variavel auxiliar de inteiros chamada 'contador'
     * @return Retorna a variavel 'contador' que tem a posição do elemento dentro da Lista
     */
	int posicao(const T& dado) const {
	int contador = 0;
	    if (listaVazia()) {
	        throw("Lista Vazia");
	    } else {
	        Elemento<T> *auxiliar = cabeca;
	        while (contador < tamanho) {
	            if (dado == auxiliar->getInfo()) {
	                return (contador);
	        }
	            auxiliar = auxiliar->getProximo();
	            contador++;
            }
            throw("Elemento não existe");
	    }
    }
    /*
     * @brief Metodo posicaoMem
     * @details Metodo para indicar a posição na memoria de determinado elemento
     * @param O parametro 'dado' é o elemento especifico a ter sua posição encontrada na memoria
     * É criado um ponteiro auxiliar chamado 'atual' e uma variavel do tipo T chamada 'dados'
     * @return Retorna um ponteiro auxiliar que indica a aponta para 'dados'
     */
	T* posicaoMem(const T& dado) const {
	    Elemento<T> *atual;
	    T dados;
	    if (listaVazia()) {
	        throw("Lista Vazia");
	    } else {
	        atual = atual->cabeca;
	        for (int i = 0; i < tamanho; i++) {
	            if (atual->getInfo() == dado) {
	                dados = atual->getInfo();
	                return &dados;
	            }
	        }
	    }
	}
    /*
     * @brief Metodo contem
     * @details Metodo indicar se um determinado dado está contido na Lista
     * @param O parametro 'dado' é o elemento especifico a ser comparado com os outros presentes na lista
     * É comparado o dado passado como parametro com todos os outros elementos da Lista
     * @return Caso o um dado igual seja encontrado retorna 'True'
     * @return Caso nem um dado igual seja encontrado retorna 'False'
     */
	bool contem(const T& dado) {
	    if (listaVazia()) {
	        throw("Lista Vazia");
	    } else {
	        Elemento<T> *auxiliar;
	        auxiliar = cabeca;
	        for (int i = 0; i < tamanho; i++) {
	            if (auxiliar->getInfo() == dado) {
	                auxiliar = auxiliar->getProximo();
	                return (true);
	            }
	        }
	        return false;
	    }
	}
    /*
     * @brief Metodo retiraDaPosicao
     * @details Metodo para retirar um elemento de uma posicao especifica da Lista
     * @param O parametro 'pos' é a posição especifica do elemento a ser retirado da lista
     * É Criado dois ponteiros auxiliares para retirar o dado da lista que são: 'anterior' e 'eliminar'
     * É também é criada uma variavel do tipo T chamada 'volta'
     * @return Caso a posição seja igual a '0' retorna o metodo 'retiraDoInicio'
     * @return Caso seja qualquer outra posição valida é retornada a variavel 'volta'
     */
	T retiraDaPosicao(int pos) {
	    Elemento<T> *anterior, *eliminar;
	    T volta;
	    if (pos >= tamanho || pos < 0) {
	        throw("Nao da");
	    } else {
	        if (pos == 0) {
	            return (retiraDoInicio());
	        } else {
	            anterior = cabeca;
	            for (int i = 0; i < pos-1; i++) {
	                anterior = anterior->getProximo();
	            }
            eliminar = anterior->getProximo();
            volta = eliminar->getInfo();
            anterior->setProximo(eliminar->getProximo());
            tamanho -=1;
            delete(eliminar);
	        }
            return(volta);
	    }
	}
    /*
     * @brief Metodo adiciona
     * @details Metodo para adicionar um elemento na Lista
     * @param O parametro 'dado' é o elemento especifico a ser adicionado da lista
     * Caso a lista esteja Vazia chama o metodo 'adicionaNoInicio' e passa como parametro o dado a ser adicionado
     * Caso contrario chama o metodo 'adicionaNaPosicao' e passa como parametro o dado a ser adicionado e o tamanho da Lista
     */
	void adiciona(const T& dado) {
        if (listaVazia()) {
            adicionaNoInicio(dado);
        } else {
            adicionaNaPosicao(dado, tamanho);
        }
	}
    /*
     * @brief Metodo retira
     * @details Metodo para retirar um elemento da Lista
     * @return Retorna a chamada do metodo 'retiraDaPosicao' com parametro 'tamanho-1'
     */
	T retira() {
	    if (listaVazia()) {
            throw("Lista vazia");
      } else {
        return retiraDaPosicao(tamanho-1);
      }
	}
    /*
     * @brief Metodo retiraEspecifico
     * @details Metodo para retirar um elemento especifico da Lista
     * @param O parametro 'dado' é o elemento especifico a ser retirado da lista
     * @return Retorna o dado a ser retirado
     */
	T retiraEspecifico(const T& dado) {
        if (listaVazia()) {
            throw("Lista Vazia");
        } else {
            return (retiraDaPosicao(posicao(dado)));
        }
	}
    /*
     * @brief Metodo adicionaEmOrdem
     * @details Metodo para adicionar elementos em uma determinada ordem na Lista
     * @param O parametro 'data' é o elemento que sera adicionado na Lista
     * É criado um ponteiro chamado 'atual' e uma variavel de inteiro 'pos' para auxiliar no funcionamento do metodo
     */
	void adicionaEmOrdem(const T& data) {
	    Elemento<T> *atual;
	    int pos;
	    if  (listaVazia()) {
	        return (adicionaNoInicio(data));
	    } else {
	        atual = cabeca;
	        pos = 1;
	        while (atual->getProximo() != NULL && maior(data, atual->getInfo())) {
	            atual = atual->getProximo();
	            pos += 1;
	        }
	        if (maior(data, atual->getInfo())) {
	            (adicionaNaPosicao(data, (pos+1)));
	        } else {
	            (adicionaNaPosicao(data, pos-1));
	        }
	    }
	}
    /*
     * @brief Metodo listaVazia
     * @details Metodo para indicar se a lista esta Vazia
     * @return Retorna 'True' caso 'tamanho' seja igual a '0'
     * @return Retorna 'False' caso 'tamanho' seja maior que '0'
     */
	bool listaVazia() const {
	    if (tamanho == 0) {
	        return (true);
        } else {
            return (false);
        }
	}
    /*
     * @brief Metodo igual
     * @details Compara dois dados de entrada do tipo 'T'.
     * @param Dados de entrada do tipo T 'dado1' e 'dado2'
     * @return Retorna 'True' caso os dados sejam iguais
     */
	bool igual(T dado1, T dado2) {
	    return (dado1 == dado2);
	}
	/*
     * @brief Metodo maior
     * @details Compara dois dados de entrada do tipo 'T'.
     * @param Dados de entrada do tipo T 'dado1' e 'dado2'
     * @return Retorna 'True' caso o 'dado1' seja maior que o 'dado2'
     */
	bool maior(T dado1, T dado2) {
        return (dado1 > dado2);
	}
	/*
     * @brief Metodo menor
     * @details Compara dois dados de entrada do tipo 'T'.
     * @param Dados de entrada do tipo T 'dado1' e 'dado2'
     * @return Retorna 'True' caso o 'dado1' seja menor que o 'dado2'
     */
	bool menor(T dado1, T dado2) {
        return (dado1 < dado2);
	}
    /*
     * @brief Metodo para destruir toda a lista
     * @details Destroi a lista atraves de um laço de repetição, evitando assim "garbage" na memória
     * Cria dois ponteiros auxiliares: 'del' e 'atual'
     * Faz um laço deletando elemento por elemento e apos isso da set na cabeca como 'null' e tamanho recebe o valor '0'
     */
	void destroiLista() {
        Elemento<T> *del, *atual;
        atual = cabeca;
        while (atual != NULL) {
            del = atual;
            atual = atual->getProximo();
            delete(del);
        }
        cabeca = NULL;
        tamanho = 0;
    }
};
