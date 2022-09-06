#include "container.h"

ContainerParticipante* ContainerParticipante::instancia = nullptr;
ContainerPeca* ContainerPeca::instancia = nullptr;
ContainerSessao* ContainerSessao::instancia = nullptr;
Peca2Participante* Peca2Participante::instancia = nullptr;

//////////////////////////////////////////////////////////

ContainerParticipante* ContainerParticipante::getInstancia(){
    if(instancia == nullptr)
        instancia = new ContainerParticipante();
    return instancia;
}


ContainerPeca* ContainerPeca::getInstancia(){
    if(instancia == nullptr)
        instancia = new ContainerPeca();
    return instancia;
}


ContainerSessao* ContainerSessao::getInstancia(){
    if(instancia == nullptr)
        instancia = new ContainerSessao();
    return instancia;
}




Peca2Participante* Peca2Participante::getInstancia(){
    if(instancia == nullptr)
        instancia = new Peca2Participante();
    return instancia;
}


///////////////////////////////////////////////////////
/////////////   Participante    ///////////////////////

bool ContainerParticipante::incluir(Usuario* usuario){
    bool valor = true;
    string key = usuario->getEmail().getValor();
    if(container.count(key) < 1)
        container[key] = *usuario;
    else
        valor = false;
    return valor;
}


bool ContainerParticipante::remover(string key){
    Peca2Participante *relacao = Peca2Participante::getInstancia();
    relacao->removerParticipante(key);
    if(container.erase(key) == 1)
        return true;
    else
        return false;
}


Usuario* ContainerParticipante::pesquisar(string key){
    Usuario* ptr = nullptr;
    if(container.count(key) == 1)
        ptr = &container[key];
    return ptr;
}


bool ContainerParticipante::atualizar(Usuario* usuario){
    string key = usuario->getEmail().getValor();
    container[key] = *usuario;
    return true;
}

///////////////////////////////////////////////////////
/////////////   Peca    ///////////////////////////////

bool ContainerPeca::incluir(Hospedagem* hospedagem){
    bool valor = true;
    string key = hospedagem->getCodigo().getValor();
    if(container.count(key) < 1)
        container[key] = *hospedagem;
    else
        valor = false;
    return valor;
}


bool ContainerPeca::remover(string key){
    Peca2Participante *r1 = Peca2Participante::getInstancia();
    r1->removerPeca(key);
    if(container.erase(key) == 1)
        return true;
    else
        return false;
}


Hospedagem* ContainerPeca::pesquisar(string key){
    Hospedagem* ptr = nullptr;
    if(container.count(key) == 1)
        ptr = &container[key];
    return ptr;
}


bool ContainerPeca::atualizar(Hospedagem* hospedagem){
    string key = hospedagem->getCodigo().getValor();
    container[key] = *hospedagem;
    return true;
}


int ContainerPeca::contar(string key){
    return container.count(key);
}



///////////////////////////////////////////////////////
/////////////   Sessao    /////////////////////////////

bool ContainerSessao::incluir(Avaliacao* avaliacao){
    string key = avaliacao->getCodigo().getValor();
    if(!(incluir(avaliacao)))
        return false;

    bool valor = true;;
    if(container.count(key) < 1)
        container[key] = *avaliacao;
    else
        valor = false;
    return valor;
}


bool ContainerSessao::remover(string key){
    if(container.erase(key) == 1)
        return true;
    else
        return false;
}


Avaliacao* ContainerSessao::pesquisar(string key){
    Avaliacao* ptr = nullptr;
    if(container.count(key) == 1)
        ptr = &container[key];
    return ptr;
}


bool ContainerSessao::atualizar(Avaliacao* avaliacao){
    string key = avaliacao->getCodigo().getValor();
    container[key] = *avaliacao;
    return true;
}





///////////////////////////////////////////////////////
/////////////   Peca2Participante    //////////////////

bool Peca2Participante::incluir(string peca, string participante){
    bool valor = true;
    ContainerPeca *cp = ContainerPeca::getInstancia();
    if(cp->contar(peca) == 0)
        return false;
    if(container.count(peca) <= 10)
        container.insert({{peca, participante}});
    else
        valor = false;
    return valor;
}


void Peca2Participante::removerPeca(string peca){
    container.erase(peca);
}


void Peca2Participante::removerParticipante(string participante){
    for(map::iterator i=container.begin(); i!=container.end(); i++){
        if(i->second == participante){
            container.erase(i);
            break;
        }
    }
}


int Peca2Participante::contar(string peca){
    return container.count(peca);
}
