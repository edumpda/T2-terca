#include <unordered_map>
#include "ControlesServico.h"
#include "container.h"

using namespace std;

bool CntrServicoAutenticacao::autenticar(Email* email, Senha* senha){
    ContainerParticipante* cp = ContainerParticipante::getInstancia();
    Usuario *participante = cp->pesquisar(email->getValor());

    if (participante == nullptr){
        return false;
    }
    else{
        if (participante->getSenha().getValor() == senha->getValor()){
            return true;
        }
        else{
            return false;
        }
    }
}

bool CntrServicoParticipante::descadastrar(Email *email){
    ContainerParticipante* cp = ContainerParticipante::getInstancia();

    return cp->remover(email->getValor());
}

bool CntrServicoParticipante::alterar(Usuario *usuario){
    ContainerParticipante* cp = ContainerParticipante::getInstancia();

    if (cp->atualizar(usuario)){
        return true;
    }
    else{
        return false;
    }
}

bool CntrServicoParticipante::cadastrar( Usuario *usuario){
    ContainerParticipante* cp = ContainerParticipante::getInstancia();
    return(cp->incluir(usuario));
}


bool CntrServicoParticipante::cadastrarEmPeca(Email *email, string peca){
    Peca2Participante *relacao = Peca2Participante::getInstancia();
    return relacao->incluir(peca, email->getValor());
}


///////////////////////////////////////////////////////
/////////////   Peca    ///////////////////////////////


bool CntrServicoPeca::incluir(Hospedagem *hospedagem){
    ContainerPeca* cp = ContainerPeca::getInstancia();
	return cp -> incluir(hospedagem);
}

bool CntrServicoPeca::excluir(Codigo *codigo){
    ContainerPeca* cp = ContainerPeca::getInstancia();

	return cp->remover(codigo->getValor());
}

bool CntrServicoPeca::editar(Hospedagem *hospedagem){
    ContainerPeca* cp = ContainerPeca::getInstancia();
    if (cp->pesquisar(hospedagem->getCodigo().getValor()) == nullptr){
        return false;
    }
    return cp->atualizar(hospedagem);
}

string CntrServicoPeca::visualizar(Codigo *codigo){
    ContainerPeca* cp = ContainerPeca::getInstancia();
    Hospedagem* hospedagem = cp->pesquisar(codigo->getValor());
    if(hospedagem == nullptr)
        return "Peca nao encontrada.";
    string saida = "Identificador: ";
    saida += hospedagem->getCodigo().getValor();
    saida += "\nNome: ";
    saida += hospedagem->getPais().getValor();
    saida += "\nTipo: ";
    saida += hospedagem->getNota().getValor();
    saida += "\nClassificacao: ";
    saida += hospedagem->getCidade().getValor();
    return saida;
}


string CntrServicoPeca::listar(){
    ContainerPeca *cp = ContainerPeca::getInstancia();
    ContainerPeca::cmap mp = cp->getMap();
    string saida = "Hospedagens:";
    for(ContainerPeca::cmap::iterator i=mp.begin();i!=mp.end();i++) {
        saida += "\n";
        saida += i->first;
    }
    return saida;
}

///////////////////////////////////////////////////////
/////////////   Sessao    /////////////////////////////

bool CntrServicoSessao::incluir(Avaliacao *avaliacao){
    ContainerSessao* cs = ContainerSessao::getInstancia();
    return cs-> incluir(avaliacao);
}

bool CntrServicoSessao::excluir(Codigo *codigo){
    ContainerSessao* cs = ContainerSessao::getInstancia();

    return cs-> remover(codigo->getValor());
}

bool CntrServicoSessao::editar(Avaliacao *avaliacao){
    ContainerSessao* cs = ContainerSessao::getInstancia();
    if (cs->pesquisar(avaliacao->getCodigo().getValor()) == nullptr){
        return false;
    }
    return cs->atualizar(avaliacao);
}

string CntrServicoSessao::visualizar(Codigo *codigo){
    ContainerSessao* cs = ContainerSessao::getInstancia();
    Avaliacao* avaliacao = cs->pesquisar(codigo->getValor());
    if(avaliacao == nullptr)
        return "Sessao nao encontrada.";
    string saida = "Identificador: ";
    saida += avaliacao->getCodigo().getValor();
    saida += "\nData: ";
    saida += avaliacao->getCodigo().getValor();
    saida += "\nHorario: ";
    saida += avaliacao->getDescricao().getValor();
    return saida;
}


string CntrServicoSessao::listar(){
    ContainerSessao *cp = ContainerSessao::getInstancia();
    ContainerSessao::cmap mp = cp->getMap();
    string saida = "Codigos de sessoes:";
    for(ContainerSessao::cmap::iterator i=mp.begin();i!=mp.end();i++) {
        saida += "\n";
        saida += i->first;
    }
    return saida;
}
