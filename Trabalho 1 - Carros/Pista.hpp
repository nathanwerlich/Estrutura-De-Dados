/*Copyright Gustavo Borges && Nathan Werlich 2016*/
#include "Carro.hpp"
#include "Fila.hpp"
#include "Eventos.hpp"
#include <iostream>

/*!
 * @brief Classe de implementação das pistas que herda de uma fila de carros.
 */
class Pista : Fila<Carro*> {

private:
	int tamanho, espacoOcupado; /*<! inteiros do tamanho da pista e do espaco que está sendo ocupado.>*/
	int velocidade, tempoParaFim; /*<! inteiros da velocidade da pista, e do tempo que o carro vai levar para chegar no seu fim>*/
	int frequencia; /*<! inteiro que indica a frequencia com que carros são criados na pista.>*/
	bool font,sumidouro; /*<! booleanos que indicam se a pista é uma fonte ou um sumidouro.>*/

public:
	/*!
	 * @brief construtor que inicializa o tamanho, velocidade, frequencia, e os carros que entram e saem da pista.
	 */
	Pista(int _tamanho, int _velocidade, int _frequencia) {
		tamanho = _tamanho;
		velocidade = _velocidade;
		frequencia = _frequencia;
		if (frequencia == 0) {
			font = false;
			sumidouro = true;
		} else if (frequencia == 1) {
			font = false;
			sumidouro = false;
		} else {
			font = true;
			sumidouro = false;
		}
	}
	/*!
	 * @brief método para adicionar um carro em uma pista  
	 * @param carro para ser adicionado na pista.
	 */
	void adicionaCarro (Carro* carro) {
		if (pistaCheia()) {
			std::cout << "um carro foi impedido de mudar de pista" << std::endl;
		} else {
			if (carro->getTamanho() + espacoOcupado == tamanho) {
				std::cout << "Um carro tentou entrar numa pista sem espaço" << std::endl;
			} else {
				this->inclui(carro);
			}
		}
	}
	/*!
	 * @brief método para marcar o evento de um carro chegando ao fim de uma pista.
	 * @param inteiro que indica o tempo atual que se encontra o programa.
	 * @return ponteiro do tipo eventos.
	 * @see tempoParaChegaoAoFimSumidouro(). 
	 * @see gerarCarros().
	 * @see chegarAoFim()
	 */
	Eventos* tempoParaChegarAoFim(int currentTime, Carro* carro) {
		Eventos* ev;
		if (this->pistaCheia() == true) {
			return ev = new Eventos(0,0,nullptr);
		} else {
			if (this->isSumidouro() == true) {
				int tempo = this->chegarAoFim(carro) + currentTime;
				ev = new Eventos(tempo, 3, this);
				return ev;
			} else {
				int tempo = this->chegarAoFim(carro) + currentTime;
				ev = new Eventos(tempo, 4,this);
				return ev;
			}
		}
	}
	/*!
	 * @brief método para gerar carros nas pistas fontes.
	 * @param inteiro que indica o tempo atual do programa.
	 * @see tempoParaChegarAoFim(). tempoParaChegarAoFimSumidouro().
	 */
	Eventos* gerarCarros(int currentTime) {
		Eventos* ev;
		if (this->pistaCheia() == true) {
			return ev = new Eventos(0,0,nullptr);
		} else {
			ev = new Eventos(frequencia+currentTime, 1,this);
			currentTime = ev->getTimer();
			return ev;
		}
	}
	/*!
	 * @brief método que calcula o tempo para um carro chegar ao fim de uma pista.
	 * @param ponteiro de carro
	 * @return inteiro que é o tempo que o carro demora para chegar ao fim.
	 */
	int chegarAoFim(Carro* carro) {
		int localCheg = tamanho - espacoOcupado - carro->getTamanho();
		int vels = velocidade/3.6;
		int tempo = 0;
		if (localCheg > 0) {
			while (vels < localCheg) {
				vels +=vels;
				tempo++;
			}
				return tempo;
			} else {
				std::cout << "Um carro tentou chegar a um local inacessivel" << std::endl;
			}
	}
	/*!
	 * @brief método para retirar o carro de uma pista.
	 * @return o carro que foi retirado.
	 */
	Carro* retiraCarro() {
		if (pistaVazia()) {
			throw "ERRO";
		} else {
			Carro* carro = primeiro();
			espacoOcupado = espacoOcupado - carro->getTamanho();
			this->retira();
			return carro;
		}
	}
	/*!
     * @brief método para retornar o primeiro carro de uma pista.
     * @return o primeiro carro da pista.
	 */
	Carro* primeiro() {
		return this->prim();
	}
	/*!
	 * @brief método para retornar se a pista está vazia.
	 * @return booleano verdadeiro se a pista estiver vazia falso caso não.
	 */
	bool pistaVazia() {
		return espacoOcupado == 0;
	}
	/*!
	 * @brief método para retornar se a pista está cheia.
	 * @return booleano verdadeiro se a pista estiver cheia falso caso não.
	 */
	bool pistaCheia() {
		return tamanho == espacoOcupado;
	}
	/*!
	 * @brief método para saber se a pista é um sumidouro.
	 * @return booleano verdadeiro se for um sumidouro falso caso não.
	 */
	bool isSumidouro() {
		return sumidouro;
	}
	/*!
	 * @brief método para saber se a pista é uma fonte.
	 * @return booleano verdadeiro se a pista for uma fonte falso caso não.
	 */
	bool isFont() {
		return font;
	}
	/*!
	 * @brief método para retornar o tamanho da pista.
	 * @return inteiro que é o tamanho da pista.
	 */
	int getTamanho() {
		return tamanho;
	}
	/*!
	 * @brief método para retornar o espaco ocupado da pista.
	 * @return inteiro que indica o espaço ocupado de uma pista.
	 */
	int getEspacoOcupado() {
		return espacoOcupado;
	}
	/*!
	 * @brief método para retornar a frequencia que os carros são criados em uma pista.
	 * @return inteiro que indica a frequencia de criação de carros.
	 */
	int getFrequencia() {
		return frequencia;
	}
};