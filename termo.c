#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>

#define TAMANHO 5
#define NUM_TENTATIVAS 6
#define LIMPAR_TECLADO (TAMANHO + 32)

void definirCor(WORD corFundo, WORD corTexto)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (corFundo << 4) | corTexto);
}

void LIMPAR_TELA(void)
{
    system("cls");
}

void COR_RESET(void)
{
    definirCor(0, 15);
}

void COR_VERDE(void)
{
    definirCor(2, 0);
}

void COR_AMARELO(void)
{
    definirCor(14, 0);
}

void COR_CINZA(void)
{
    definirCor(7, 0);
}

const char PALAVRAS[][TAMANHO + 1] = {
    "SAGAZ", "AMAGO", "TERMO", "NITRO", "EXITO", "MEXER", "NOBRE", "ETICA",
    "SENSO", "AFETO", "ALGOZ", "FAZER", "PLENA", "TENUE", "ASSIM", "SOBRE",
    "MUTUA", "AQUEM", "PODER", "SECAO", "VIGOR", "SUTIL", "POREM", "FOSSE",
    "CERNE", "IDEIA", "SANAR", "AUDAZ", "MORAL", "QUICA", "MUITO", "JUSTO",
    "DESDE", "HONRA", "SONHO", "TORPE", "AMIGO", "RAZAO", "EGIDE", "ICONE",
    "ETNIA", "FUTIL", "ANEXO", "DENGO", "HAVER", "LAPSO", "ENTAO", "TEMPO",
    "EXPOR", "SEARA", "BOCAL", "SABER", "HABIL", "MUTUO", "GRACA", "CASAL",
    "XIBIU", "OBICE", "AVIDO", "DIZER", "ARDIL", "ESTAR", "PESAR", "DEVER",
    "CAUSA", "TENAZ", "AINDA", "TEMOR", "SENDO", "CRIVO", "BRADO", "PARIA",
    "COSER", "APICE", "GENRO", "COMUM", "POSSE", "PROLE", "ASSAZ", "CORJA",
    "ANIMO", "FUGAZ", "CEDER", "PAUTA", "DETEM", "CENSO", "CULTO", "ANSIA",
    "ATROZ", "DIGNO", "MUNDO", "FORTE", "MESMO", "VULGO", "VICIO", "SAUDE",
    "GLEBA", "CRIAR", "TODOS", "COZER", "REVES", "JEITO", "PUDOR", "DOGMA",
    "VALHA", "DENSO", "NENEM", "LOUCO", "ORDEM", "LIMBO", "ATRAS", "REGRA",
    "PEDIR", "FELIZ", "HOMEM", "AJUDA", "CLAVA", "USURA", "MERCE", "IMPOR",
    "BANAL", "COISA", "JUIZO", "FALSO", "RURAL", "LEGAL", "FORMA", "FALAR",
    "CERTO", "SABIO", "PROSA", "SERVO", "TENRO", "PIFIO", "POSSO", "PRESA",
    "DESSE", "HEROI", "CUNHO", "DEVIR", "FACIL", "VIRIL", "VONDE", "VALOR",
    "VISAR", "LINDA", "MANSO", "SERIO", "EBRIO", "GUISA", "MAGOA", "ACASO",
    "MEIGA", "PUDER", "IMPIO", "FLUIR", "AFAGO", "LUGAR", "REACA", "TEMER",
    "PLATO", "GARBO", "PRAXE", "UNIAO", "GERAR", "BURRO", "MATIZ", "OBTER",
    "OBVIO", "BRUMA", "CISMA", "AFINS", "VENIA", "EXODO", "PLENO", "CRISE",
    "ALIBI", "RITMO", "TEDIO", "FLUXO", "MORTE", "LEVAR", "SENIL", "HAVIA",
    "OLHAR", "CASTA", "TOMAR", "ENFIM", "VISAO", "GENIO", "OUVIR", "PARVO",
    "PRUMO", "CABAL", "RELES", "PARCO", "BREGA", "FALTA", "CALMA", "VITAL",
    "OUTRO", "BRAVO", "TECER", "FAVOR", "PULHA", "TERRA", "RETER", "VIVAZ",
    "VIVER", "SABIA", "AMENO", "FORCA", "UNICO", "TENDO", "LAICO", "PASSO",
    "VALIA", "NICHO", "GRATO", "ACHAR", "REVER", "CARMA", "NOSSA", "PAPEL",
    "NOCAO", "RANCO", "POSSA", "POBRE", "ROGAR", "NOITE", "DUBIO", "FARDO",
    "ATIVO", "FACAM", "PRIME", "FARSA", "COESO", "EPICO", "FATOR", "ANELO",
    "CLARO", "LEIGO", "LIDER", "SESTA", "SELAR", "OBITO", "CIUME", "VAZIO",
    "CISAO", "CESTA", "SINTO", "SONSO", "CITAR", "FICAR", "DETER", "ATUAR",
    "VELHO", "GENTE", "HASTE", "ADIAR", "TENDE", "HUMOR", "FONTE", "REVEL",
    "PONTO", "IDEAL", "SULCO", "ARDUO", "LABOR", "SENAO", "IGUAL", "REMIR",
    "MARCO", "TERNO", "FEIXE", "HIATO", "EXATO", "AMPLO", "CAPAZ", "VEMOS",
    "TANTO", "DEBIL", "LAVRA", "RELVA", "CAUDA", "CICLO", "TENRA", "INATA",
    "JOVEM", "VARAO", "CHUVA", "OTICA", "RAIVA", "GESTO", "AMBOS", "POUCO",
    "CACAR", "TOADA", "VELAR", "SONSA", "COCAR", "APOIO", "SERIE", "VACUO",
    "IMUNE", "XEQUE", "ALGUM", "FEITO", "FARAO", "VIMOS", "HORDA", "CARRO",
    "FUSAO", "ENTRE", "LEITO", "COESA", "SORTE", "PROBO", "MINHA", "TRAMA",
    "CRUEL", "SENTE", "DOIDO", "ANUIR", "LAZER", "FRASE", "BRISA", "IMPAR",
    "VERSO", "CHATA", "RIGOR", "MASSA", "TORCO", "BLASE", "PEGAR", "BOTAR",
    "PRECE", "MAIOR", "SEITA", "ARENA", "DORSO", "SIGNO", "FAUNA", "MOCAO",
    "FUROR", "SAIBA", "AGORA", "LIVRO", "PLANO", "LIAME", "VETOR", "COMER",
    "PRESO", "COVIL", "SENDA", "OCASO", "CREDO", "CASTO", "FLORA", "MORAR",
    "PRAIA", "PECHA", "FAINA", "NUNCA", "ALIAS", "DOCIL", "ADEUS", "HOUVE",
    "PESTE", "ARDOR", "ARIDO", "MUDAR", "SETOR", "MANHA", "PARTE", "AMBAS",
    "PEIXE", "ANTRO", "RISCO", "REZAR", "VISSE", "PAJEM", "JUNTO", "VIRUS",
    "ESTAO", "VULTO", "SALVO", "GRUPO", "MESES", "AVARO", "CAMPO", "OTIMO",
    "SAIDA", "BEATA", "BREVE", "VASTO", "ACESO", "ANTES", "MORRO", "SINAL",
    "CONTA", "ANDAR", "VERBO", "ANAIS", "LENDA", "REGER", "AUERO", "BANZO",
    "OXALA", "PRADO", "FUGIR", "ACIMA", "OPCAO", "SERAO", "FESTA", "VILAO",
    "CHULO", "RAPAZ", "SEGUE", "NACAO", "TEXTO", "LEITE", "MOTIM", "BIRRA",
    "INDIO", "FRUIR", "TIRAR", "TRETA", "PARAR", "BRAVA", "FITAR", "ATRIO",
    "PUXAR", "IDOLO", "JAZIA", "BONUS", "ATOMO", "FILHO", "ALUDE", "TOSCO",
    "TURBA", "GERIR", "REINO", "TENSO", "PRAZO", "PROVA", "TRAGA", "NORMA",
    "EPOCA", "EXAME", "MANHA", "VORAZ", "ACESA", "CORPO", "CHEIO", "SARCA",
    "PRETO", "LIGAR", "MALTA", "BANDO", "AONDE", "NOSSO", "ARCAR", "MAGIA",
    "QUASE", "VENAL", "COPIA", "FATOS", "SINHA", "LOGRO", "LONGE", "AVIAO",
    "PSICO", "ANCIA", "AFORA", "FATAL", "DESSA", "CERTA", "PRAGA", "QUOTA",
    "SEXTA", "NIVEL", "OASIS", "FIXAR", "MENTE", "MESSE", "APEGO", "NODOA",
    "LIDAR", "GLOSA", "POMPA", "PERDA", "APELO", "PARCA", "VERVE", "TOCAR",
    "ALADO", "JIRAU", "CAIXA", "COITO", "LIVRE", "FRACO", "SUMIR", "TINHA",
    "PORTA", "VEZES", "SOLDO", "GRAVE", "FIRME", "LINDO", "CANON", "BATER",
    "OPACO", "SOLTO", "BESTA", "IRMAO", "FAIXA", "ASTRO", "SALVE", "SABIA",
    "ATUAL", "TURVA", "ELITE", "VIRAO", "TRUPE", "DOIDO", "SUPRA", "NAVIO",
    "FENDA", "DEIXA", "GRATA", "JUNCO", "CIOSO", "ALCAR", "TRONO", "AUTOR",
    "CURSO", "PIQUE", "PARVA", "BIOMA", "CHATO", "EXIJO", "BICHO", "DESTA",
    "MACIO", "DOUTO", "ALUNO", "VIRIA", "PAGAO", "ETICO", "RESES", "KOALA",
    "MENOS", "CABER", "CALDA", "FICHA", "POSTO", "RADIO", "ABUSO", "VIDEO",
    "LOCUS", "CULPA", "SUPOR", "LAPIS", "ZELAR", "TULHA", "GOSTO", "SUPER",
    "VERBA", "SUAVE", "CALAO", "ADVIR", "AGUDO", "CLARA", "EXTRA", "SALSA",
    "RETEM", "BAIXO", "MOLHO", "TORSO", "PRIVE", "PIADA", "FACHO", "SITIO",
    "PEITO", "RUINA", "VINHA", "VOSSO", "TURMA", "IGNEO", "PASSA", "PODIO",
    "TRACO", "ASILO", "AVIDA", "PILAR", "ESTIO", "ORFAO", "COMBO", "LEIGA",
    "CHAMA", "MOSTO", "TURVO", "MUSEU", "PAREO", "ACOES", "REFEM", "AMENA",
    "POETA", "PISAR", "FOREM", "LASSO", "ACOLA", "MESMA", "BRABO", "LOCAL",
    "MEDIR", "ERETO", "MEIGO", "BUSCA", "DRAMA", "OPTAR", "TESTE", "FINDA",
    "METIE", "POEMA", "CLIMA", "TENTO", "CUTIS", "AUTOS", "AVISO", "SURJA",
    "FOLGA", "CORAL", "FACTO", "COCHO", "GERAL", "RUMOR", "SISAL", "AMIGA",
    "ROUCA", "PAIRA", "CALMO", "TACHA", "PESCA", "FEROZ", "IDOSO", "CETRO",
    "BOATO", "RUBRO", "VOLTA", "URGIA", "PACTO", "ACUDE", "FEUDO", "GOLPE",
    "MOVEL", "CRIME", "LICAO", "MONGE", "ATEIA", "CORSO", "PALMA", "DAQUI",
    "RISTE", "EBANO", "MANGA", "ARCAO", "TETRA", "PONHA", "CASAR",
    "NATAL", "CARTA", "BENCA", "FALHA", "MONTE", "SALDO", "AROMA", "VERDE",
    "CONTO", "CACHO", "ESCOL", "ITENS", "VETAR", "VIGIA", "BRIGA", "HOSTE",
    "PLUMO", "GRAMA", "TRIBO", "TARDE", "FORUM", "PASMO", "MANGA", "FAZIA",
    "ORNAR", "LETAL", "AMADA", "TROCA", "VENTO", "MORNA", "UNICA", "SUCIA",
    "SOSIA", "CHEFE", "RIVAL", "CIVIL", "FRUTO", "UTEIS", "NUVEM", "ORGAO",
    "PLAGA", "ROUPA", "TCHAU", "VENHA", "SARAU", "JOGAR", "PINHO", "AREIA",
    "VAZAO", "PLEBE", "ATIMO", "PENTA", "JEJUM", "BERRO", "TALCO", "NESSE",
    "VIRAR", "ARADO", "CARGO", "COVER", "SEIXO", "LESSE", "FOSSO", "MACRO",
    "PERTO", "CATRE", "HASTA", "MIDIA", "MAGNA", "GIRIA", "AXILA", "ROCHA",
    "TUTOR", "DRAGA", "LEGUA", "FINJO", "BEIJO", "TIVER", "VAROA", "TICAO",
    "BRUTO", "TODAS", "FARTA", "TROCA", "INTER", "CALOR", "BRUTA", "RENDA",
    "POMAR", "TRAJE", "ASSAR", "GABAR", "DESTE", "TENHA", "CLOSE", "SANTO",
    "ARFAR", "XUCRO", "DANCA", "VADIO", "TRATO", "SURTO", "ESTRO", "PORTE",
    "AMBAR", "AMADO", "GURIA", "VERAO", "NESSA", "LOGOS", "SILVO", "ODIAR",
    "FEITA", "CHULA", "VISTA", "NESTA", "DEPOR", "AVIAR", "AGAPE", "MAMAE",
    "CANTO", "LAUDO", "CENHO", "MARCA", "JANTA", "VEDAR", "BAZAR", "ETAPA",
    "FOSSA", "GROTA", "CANSO", "BOLSA", "SALMO", "CERCA", "PAVOR", "MINAR",
    "CHEIA", "DENSA", "RECEM", "CIFRA", "IRADO", "CLERO", "COROA", "VISTO",
    "REGIO", "URDIR", "CINTO", "FERPA", "VAGAR", "LETRA", "BURRA", "RURAL",
    "HORTO", "QUAIS", "RUIDO", "BUCHO", "INVES", "LARGO", "FOLHA", "JAZER",
    "ESGAR", "MOLDE", "SEGAR", "PROTO", "SIMIO", "LESAO", "SOTAO", "PAIOL",
    "FINAL", "PUGNA", "UBERE", "TRAGO", "VELHA", "FUNDO", "PENSO", "MORFO",
    "LESTO", "NARCO", "QUEDA", "VASTA", "ALAMO", "PASMA", "UFANO", "OLHOS",
    "ARDIS", "CEITA", "DERAM", "LINHA", "PODAR", "TROCO", "PICHE", "APEAR",
    "FAROL", "FOLIA", "POLIS", "PRECO", "VIGER", "BULIR", "TROCO", "UMIDO",
    "AUDIO", "FROTA", "OUTRA", "CHAVE", "MOCHO", "PEITA", "DISSO", "NESTE",
    "MATAR", "MONTA", "COSMO", "ILESO"};

// void escolherPalavra();
// int verificarPalpite();
// int verficarApenasLetras();
// void tranformarMaiusculo();
// void avaliarPalpite();
// void exibirResultado();
// void exibirTeclado();
// void atualizarTeclado();
// int vencerJogo();

int main(void)
{
    char palavraSecreta[TAMANHO + 1];
    char palpite[LIMPAR_TECLADO];
    char resultado[TAMANHO + 1];
    char letrasUsadas[26];
    char statusLetras[26];

    for (int i = 0; i < 26; i++)
    {
        letrasUsadas[i] = 'A' + i;
        statusLetras[i] = '?';
    }

    srand((unsigned int)time(NULL));
    // escolherPalavra(palavraSecreta);

    LIMPAR_TELA();
    printf("=================================================\n");
    printf("                 JOGO TERMO\n");
    printf("=================================================\n");
    printf("Adivinhe a palavra secreta de %d letras.\n", TAMANHO);
    printf("Voce tem %d tentativas.\n\n", NUM_TENTATIVAS);

    COR_VERDE();
    printf(" A ");
    COR_RESET();
    printf(" = letra certa, posicao certa\n");
    COR_AMARELO();
    printf(" A ");
    COR_RESET();
    printf(" = letra existe, posicao errada\n");
    COR_CINZA();
    printf(" A ");
    COR_RESET();
    printf(" = letra nao esta na palavra\n\n");

//Temporario pra teste pq por algum motivo no meu Windows ele só abre e fecha mas no VsCode ele funciona normal, então vou deixar esse getchar() aqui pra não fechar o programa
    printf("\nPressione Enter para sair...");
    getchar();
    return 0;
}