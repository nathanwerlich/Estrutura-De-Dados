/* Copyright 2016 - Nathan Sargon Werlich */
#include "ElementoDuplo.hpp" /*!< inclui o arquivo Elemento.hpp */
template<typename T> /*!< template generico do tipo T*/
    // Classe para a implementação de uma Lista Circular Dupla
    /*!
     *   \author Nathan Sargon Werlich.
     *   \since 09/05/16
     *   \version 1.0
     */

class ListaDuplaCirc {
 private:
	ElementoDuplo<T>* sentinela; /*< Criando um ponteiro sentinela da lista*/
	int tamanho; /*< Variavel que indica qual o tamanho atual da lista */
	ElementoDuplo<T>* cabeca; /*< Criando um ponteiro para ser cabeca da lista*/

 public:
	ListaDuplaCirc() {
    //! Construtor da Classe ListaDuplaCirc
    /*!
     * A variavel 'tamanho' recebe o tamanho atual da lista, ou seja, '0'
     * É inicializado um elemento chamado 'sentinela' para ser a sentinela da lista.
     * O ponteiro 'cabeca' recebe 'NULL'
     */
	    tamanho = 0;
	    sentinela = new ElementoDuplo<T> (0, sentinela, sentinela);
	    cabeca = NULL;
	}
	//! Destrutor
    /*!
     * Destrutor da classe ListaCirc. 
     * A variavel 'tamanho' passa a valer '0'
     * É chamado o metodo 'destroiLista()' para eliminar a lista por completo
     */
	~ListaDuplaCirc() {
	    destroiListaDuplo();
	}
    /*
     * @brief Metodo adicionaNoInicio
     * @details Metodo para adicionar um elemento no inicio da Lista
     * @param O parametro 'dado' é o elemento a ser adicionado no inicio da Lista
     * É Criado um ponteiro chamado 'novo' e é passado como parametro desse panteiro 'dado' e 'cabeca'
     */
	void adicionaNoInicioDuplo(const T& dado) {
	    ElementoDuplo<T> *novo = new ElementoDuplo<T>(dado, nullptr, nullptr);
	    if (novo == NULL) {
	        throw("Lista Cheia");
	    } else {
	        if (tamanho == 0) {
                novo->setProximo(sentinela);
                novo->setAnterior(sentinela);
                sentinela->setProximo(novo);
                sentinela->setAnterior(novo);
	            tamanho += 1;
	        } else {
                novo->setProximo(sentinela->getProximo());
                novo->setAnterior(sentinela);
                sentinela->setProximo(novo);
	            tamanho += 1;
	        }
	    }
	}
    /*
     * @brief Metodo retiraDoInicioDuplo
     * @details Metodo para retirar um elemento do inicio da Lista e libera o endereço de memória que estava sendo usado pelo elemento
     * Cria um ponteiro auxiliar chamado 'saiu'
     * Cria uma varaivel auxiliar chamada 'volta'
     * @return Retorna o elemento retirado que esta contido na varaivel 'volta'
     */
	T retiraDoInicioDuplo() {
	    ElementoDuplo<T> *saiu;
        T volta;
        if (listaVazia()) {
            throw("Lista vazia");
        } else {
            saiu = sentinela->getProximo();
            volta = saiu->getInfo();
            sentinela->setProximo(saiu->getProximo());
            saiu->getProximo()->setAnterior(sentinela);
            tamanho -= 1;
            delete (saiu);
            return (volta);
        }
	}
    /*
     * @brief Metodo eliminaDoInicioDuplo
     * @details Metodo para eliminar um elemento do inicio da Lista e libera o endereço de memória que estava sendo usado pelo elemento
     * Cria um ponteiro auxiliar chamado 'saiu'
     */
	void eliminaDoInicioDuplo() {
	    ElementoDuplo<T> *saiu;
	    if (listaVazia()) {
	        throw("Erro Lista Vazia");
	    } else {
	        saiu = sentinela->getProximo();
	        sentinela->setProximo(saiu->getProximo());
	        saiu->getProximo()->setAnterior(sentinela);
	        tamanho -= 1;
	        delete(saiu);
	    }
	}
    /*
     * @brief Metodo adicionaNaPosicaoDuplo
     * @details Metodo para adicionar em uma posição especifica
     * @param O parametro 'dado' é o dado a ser alocado em determinada posição
     * @poram O parametro 'pos' é a posição que o dado será adicionado
     * Verifica se a posição é valida
     * Verifica se a posição é '0', caso seja, chama o metodo adicionaNoInicio e passa como parametro 'dado'
     * Cria dois ponteiros auxiliares chamados 'novo' e 'anterior'
     */
	void adicionaNaPosicaoDuplo(const T& dado, int pos) {
	    if (pos < 0 || pos > tamanho) {
            throw("ERRO DE POSICAO");
        } else if (pos == 0) {
            adicionaNoInicioDuplo(dado);
        } else {
            ElementoDuplo<T> *novo, *anterior;
            novo = sentinela->getProximo();
            int posi = 0;
            while (posi < pos-1) {
                novo = novo->getProximo();
                posi += 1;
            }
            anterior = novo->getProximo();
            novo->getProximo()->setAnterior(novo);
            novo->setProximo(new ElementoDuplo<T>(dado, anterior, novo));
            tamanho += 1;
        }
	}
    /*
     * @brief Metodo posicaoDuplo
     * @details Metodo que indica a posição de um elemento contido na Lista
     * @param O parametro 'dado' é o elemento a ter sua posição encontrada
     * É criado uma variavel auxiliar de inteiros chamada 'contador'
     * @return Retorna a variavel 'contador' que tem a posição do elemento dentro da Lista
     */
	int posicaoDuplo(const T& dado) const {
	int contador = 0;
	    if (listaVazia()) {
	        throw("Lista Vazia");
	    } else {
	        ElementoDuplo<T> *auxiliar = sentinela->getProximo();
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
     * @brief Metodo posicaoMemDuplo
     * @details Metodo para indicar a posição na memoria de determinado elemento
     * @param O parametro 'dado' é o elemento especifico a ter sua posição encontrada na memoria
     * É criado um ponteiro auxiliar chamado 'atual' e uma variavel do tipo T chamada 'dados'
     * @return Retorna um ponteiro auxiliar que indica a aponta para 'dados'
     */
	T* posicaoMemDuplo(const T& dado) const {
	    ElementoDuplo<T> *atual;
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
     * @brief Metodo contemDuplo
     * @details Metodo indicar se um determinado dado está contido na Lista
     * @param O parametro 'dado' é o elemento especifico a ser comparado com os outros presentes na lista
     * É comparado o dado passado como parametro com todos os outros elementos da Lista
     * @return Caso o um dado igual seja encontrado retorna 'True'
     * @return Caso nem um dado igual seja encontrado retorna 'False'
     */
	bool contemDuplo(const T& dado) {
	    if (listaVazia()) {
	        return (false);
	    } else {
	        ElementoDuplo<T> *auxiliar;
	        auxiliar = sentinela->getProximo();
	        for (int i = 0; i < tamanho; i++) {
	            if (auxiliar->getInfo() == dado) {
	                return (true);
	            }
	       	auxiliar = auxiliar->getProximo();
	        }
	        return false;
	    }
	}
    /*
     * @brief Metodo retiraDaPosicaoDuplo
     * @details Metodo para retirar um elemento de uma posicao especifica da Lista
     * @param O parametro 'pos' é a posição especifica do elemento a ser retirado da lista
     * É Criado dois ponteiros auxiliares para retirar o dado da lista que são: 'anterior' e 'eliminar'
     * É também é criada uma variavel do tipo T chamada 'volta'
     * @return Caso a posição seja igual a '0' retorna o metodo 'retiraDoInicio'
     * @return Caso seja qualquer outra posição valida é retornada a variavel 'volta'
     */
	T retiraDaPosicaoDuplo(int pos) {
	    ElementoDuplo<T> *anterior, *eliminar;
	    T volta;
	    if (pos >= tamanho || pos < 0) {
	        throw("Nao da");
	    } else {
	        if (pos == 0) {
	            return (retiraDoInicioDuplo());
	        } else {
	            anterior = sentinela->getProximo();
	            for (int i = 0; i < pos-1; i++) {
	                anterior = anterior->getProximo();
	            }
            eliminar = anterior->getProximo();
            volta = eliminar->getInfo();
            anterior->setProximo(eliminar->getProximo());
            eliminar->getProximo()->setAnterior(anterior);
            tamanho -=1;
            delete(eliminar);
	        }
            return(volta);
	    }
	}
    /*
     * @brief Metodo adicionaDuplo
     * @details Metodo para adicionar um elemento na Lista
     * @param O parametro 'dado' é o elemento especifico a ser adicionado da lista
     * Caso a lista esteja Vazia chama o metodo 'adicionaNoInicio' e passa como parametro o dado a ser adicionado
     * Caso contrario chama o metodo 'adicionaNaPosicao' e passa como parametro o dado a ser adicionado e o tamanho da Lista
     */
	void adicionaDuplo(const T& dado) {
        if (listaVazia()) {
            adicionaNoInicioDuplo(dado);
        } else {
            adicionaNaPosicaoDuplo(dado, tamanho);
        }
	}
    /*
     * @brief Metodo retiraDuplo
     * @details Metodo para retirar um elemento da Lista
     * @return Retorna a chamada do metodo 'retiraDaPosicao' com parametro 'tamanho-1'
     */
	T retiraDuplo() {
	    if (listaVazia()) {
            throw("Lista vazia");
        } else {
            return retiraDaPosicaoDuplo(tamanho-1);
        }
	}
    /*
     * @brief Metodo retiraEspecificoDuplo
     * @details Metodo para retirar um elemento especifico da Lista
     * @param O parametro 'dado' é o elemento especifico a ser retirado da lista
     * @return Retorna o dado a ser retirado
     */
	T retiraEspecificoDuplo(const T& dado) {
        if (listaVazia()) {
            throw("Lista Vazia");
        } else {
            return (retiraDaPosicaoDuplo(posicaoDuplo(dado)));
        }
	}
    /*
     * @brief Metodo mostra
     * @details Metodo para mostra qual elemento está em determinada posição da lista
     * @param O parametro 'pos' é a posição que pegaremos o dado a ser mostrado
     * @return Retorna a informação do presente no dado da posição passada
     */
	T mostra(int pos) {
        if (listaVazia()) {
            throw("ERROPOSICAO");
        } else {
            if (pos < 0 || pos > tamanho) {
                throw("POSICAO INVALIDA");
            } else {
                ElementoDuplo<T> *aux = sentinela->getProximo();
                for (int i = 0; i < pos; i++) {
                    aux = aux->getProximo();
                }
                return (aux->getInfo());
            }
        }
	}
    /*
     * @brief Metodo adicionaEmOrdem
     * @details Metodo para adicionar elementos em uma determinada ordem na Lista
     * @param O parametro 'data' é o elemento que sera adicionado na Lista
     * É criado um ponteiro chamado 'atual' e uma variavel de inteiro 'pos' para auxiliar no funcionamento do metodo
     */
	void adicionaEmOrdem(const T& data) {
	    ElementoDuplo<T> *atual;
	    int pos;
	    if  (listaVazia()) {
	        return (adicionaNoInicioDuplo(data));
	    } else {
	        atual = sentinela->getProximo();
	        pos = 1;
	        while (atual->getProximo() != NULL && maior(data, atual->getInfo())) {
	            atual = atual->getProximo();
	            pos += 1;
	        }
	        if (maior(data, atual->getInfo())) {
	            (adicionaNaPosicaoDuplo(data, (pos+1)));
	        } else {
	            (adicionaNaPosicaoDuplo(data, pos-1));
	        }
	    }
	}
    /*
     * @brief Metodo verUltimo
     * @details Metodo para indicar qual o ultimo elemento da lista
     * @return Retorna 'tamanho-1' 
     */
	int verUltimo() {
	    return (tamanho-1);
	}
    /*
     * @brief Metodo listaVazia()
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
     * @return Retorna 'True' caso o 'dado1' seja igual ao 'dado2'
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
	void destroiListaDuplo() {
        ElementoDuplo<T> *del, *atual;
        atual = sentinela->getProximo();
        int i = 0;
        while (i != tamanho) {
            del = atual;
            atual = atual->getProximo();
            delete(del);
            i++;
        }
        tamanho = 0;
	}
};
