struct Plateau{
    int tab[8][8]; // 8 lignes, 8 colonnes
    // 0 = case vide
    // 1 à 8 = pions noirs
    // 9 à 10 = tours noires
    // 11 à 12 = cavaliers noirs
    // 13 à 14 = fous noirs
    // 15 = reine noire
    // 16 = roi noir
    // 17 à 24 = pions blancs
    // 25 à 26 = tours blanches
    // 27 à 28 = cavaliers blancs
    // 29 à 30 = fous blancs
    // 31 = reine blanche
    // 32 = roi blanc

};

struct Coups{
    int id; // 0 à 99
    int x_init; // 1 à 8
    int y_init; // 1 à 8
    int x_final; // 1  à 8
    int y_final; // 1 à 8

};

struct Historique{
    Coups tab[100]; // 100 coups max(volontairement élevé pour avoir une marge)
    unsigned int Nb_coups; // Nombre de coups joués
};

struct PiecePrise{
    int tab[32]; // 32 pièces max
    unsigned int Nb_pieces; // Nombre de pièces prises
};

struct Game{
    Plateau plateau; // Plateau de jeu
    // Historique historique; // Historique des coups joués NON DISPONIBLE
    PiecePrise piece_prise; // Liste des pièces prises
    int tour; // Personne qui joue : 0 = noir, 1 = blanc
};

struct Mask{
    int tab[8][8]; // 8 lignes, 8 colonnes
    // 0 Classique
    // 1 Rouge (Attaque)
    // 2 Vert (Défense)
    // 3 Jaune (?)
    // 4 Bleu (Déplacement)
    // 5 Violet (Déplacement + Attaque)
    // 6 Cyan (Déplacement + Défense)
    // 7 Gris (Déplacement + Attaque + Défense)
};