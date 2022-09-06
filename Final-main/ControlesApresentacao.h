#ifndef CONTROLES_APRESENTACAO_H
#define CONTROLES_APRESENTACAO_H

#include "Dominios.h"
#include "Entidades.h"
#include "Interfaces.h"

#ifdef _WIN32   // OS Windows
#define CLR system("CLS")
#elif __linux__  // OS Linux
#define CLR system("clear")
#endif

class CntrApresentacaoControle {
    //180030353
    private:
        Email email;
        IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
        IApresentacaoParticipante *cntrApresentacaoParticipante;
        IApresentacaoPSS *cntrApresentacaoPSS;

    public:
        void executar();
        void setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao *cntr) {cntrApresentacaoAutenticacao = cntr;};
        void setCntrApresentacaoParticipante(IApresentacaoParticipante *cntr) {cntrApresentacaoParticipante = cntr;};
        void setCntrApresentacaoPSS(IApresentacaoPSS *cntr) {cntrApresentacaoPSS = cntr;};
};



class CntrApresentacaoAutenticacao: public IApresentacaoAutenticacao {
    //180030353
    private:
        IServicoAutenticacao *cntr;

    public:
        bool autenticar(Email *email) override;
        void setCntrServicoAutenticacao(IServicoAutenticacao *cntr) override {this->cntr = cntr;};

};


class CntrApresentacaoParticipante: public IApresentacaoParticipante {
    //180030353
    private:
        IServicoParticipante *cntr;

    public:
        bool editar(Email *email);
        bool cadastrar() override;
        void executar(Email *email) override;
        void setCntrServicoParticipante(IServicoParticipante *cntr) override {this->cntr = cntr;};
};


class CntrApresentacaoPSS: public IApresentacaoPSS {
    //180030353
    private:
        void editar();
        bool editarHospedagem();
        bool editarAvaliacao();

        void incluir();
        bool incluirHospedagem();
        bool incluirAvaliacao();

        void excluir();
        bool excluirHospedagem();
        bool excluirAvaliacao();

        void visualizar();

        IServicoPeca *cntrPeca;
        IServicoSessao *cntrSessao;

    public:
        void executar(Email *email) override;
        void executar() override;
        void setCntrServicoPeca(IServicoPeca *cntrPeca) override {this->cntrPeca = cntrPeca;};
        void setCntrServicoSessao(IServicoSessao *cntrSessao) override {this->cntrSessao = cntrSessao;};
};


#endif // CONTROLES_APRESENTACAO_H
