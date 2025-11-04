/* ************************************************************************** */
/*                         COURS C++ - EXERCICE 01                            */
/*                    PhoneBook - Explication complète                        */
/* ************************************************************************** */

// ============================================================================
// 1. CONCEPTS C++ DE BASE
// ============================================================================

/*
 * LES CLASSES - Structure améliorée avec fonctions
 * 
 * En C : struct avec des données
 * En C++ : class avec données + fonctions pour les manipuler
 */

class Contact {
private:  // Accessible UNIQUEMENT dans la classe
    std::string first_name;
    std::string last_name;
    
public:   // Accessible de partout
    void set_first_name(const std::string& str);
    std::string get_first_name() const;
};

/*
 * Pourquoi private et public ?
 * - private : Protège les données (personne ne peut modifier directement)
 * - public : Les fonctions pour accéder/modifier les données de façon contrôlée
 * 
 * C'est le principe d'ENCAPSULATION = cacher les détails d'implémentation
 */


// ============================================================================
// 2. CONSTRUCTEUR - Initialise l'objet
// ============================================================================

Contact::Contact() {
    this->first_name = "";  // 'this' = pointeur vers l'objet actuel
    this->last_name = "";
    // Appelé automatiquement quand tu crées un Contact
}

/*
 * Le constructeur a le MÊME NOM que la classe
 * Pas de type de retour (même pas void)
 * Appelé automatiquement : Contact c; // Constructeur appelé ici !
 */


// ============================================================================
// 3. DESTRUCTEUR - Nettoie avant la suppression
// ============================================================================

Contact::~Contact() {
    // Rien à faire ici car pas de malloc
    // Mais si tu avais alloué de la mémoire, c'est ici qu'il faudrait free
}

/*
 * Le destructeur commence par ~
 * Appelé automatiquement quand l'objet est détruit
 * Utile pour libérer des ressources (fichiers, mémoire, etc.)
 */


// ============================================================================
// 4. GETTERS ET SETTERS - Accès contrôlé aux données
// ============================================================================

// SETTER - Modifie une donnée privée
void Contact::set_first_name(const std::string& str) {
    this->first_name = str;
}

// GETTER - Lit une donnée privée (SANS LA MODIFIER)
std::string Contact::get_first_name() const {
    return this->first_name;
}

/*
 * Le 'const' après la fonction = "cette fonction NE MODIFIE PAS l'objet"
 * Le '&' dans 'const std::string& str' = passage par RÉFÉRENCE
 *   - Comme un pointeur mais plus simple
 *   - Évite de copier toute la string (plus rapide)
 *   - Le 'const' empêche la modification
 */


// ============================================================================
// 5. LES STREAMS - Flux d'entrée/sortie
// ============================================================================

/*
 * std::cin   - Input (comme scanf)
 * std::cout  - Output (comme printf)
 * std::endl  - Retour à la ligne + flush du buffer
 * 
 * Exemples :
 */

std::string name;
std::cout << "Enter name: ";      // Affiche sans retour à la ligne
std::cin >> name;                  // Lit un mot (s'arrête à l'espace)
std::getline(std::cin, name);      // Lit une ligne complète (avec espaces)


// ============================================================================
// 6. STD::STRING - Chaînes de caractères dynamiques
// ============================================================================

std::string name = "John";

name.empty()        // true si vide, false sinon
name.length()       // taille de la string
name.substr(0, 9)   // sous-chaîne : du caractère 0 à 8 (9 caractères)
name.substr(0, 9) + "."  // Concaténation

/*
 * Pas besoin de malloc/free !
 * C++ gère la mémoire automatiquement avec le destructeur de std::string
 */


// ============================================================================
// 7. STRUCTURE DU PHONEBOOK
// ============================================================================

class PhoneBook {
private:
    Contact contacts[8];  // Tableau STATIQUE de 8 contacts (pas de malloc!)
    int current_index;    // Nombre de contacts actuels (0 à 8)
    int add_index;        // Position pour ajouter le prochain (0 à 7)
    
    void print_field(const std::string& field) const;  // Fonction helper

public:
    PhoneBook();  // Constructeur
    void add_contact(const Contact& contact);
    void search_contacts() const;
    ~PhoneBook();
};

/*
 * contacts[8] : Tableau STATIQUE
 *   - Pas besoin de malloc
 *   - Mémoire allouée sur la pile (stack)
 *   - Automatiquement libérée quand PhoneBook est détruit
 */


// ============================================================================
// 8. LOGIQUE ADD - Ajouter un contact
// ============================================================================

void PhoneBook::add_contact(const Contact& contact) {
    contacts[add_index] = contact;     // Remplace le contact à cette position
    add_index = (add_index + 1) % 8;   // Passe à la position suivante (0-7)
    if (current_index < 8)
        current_index++;               // Incrémente jusqu'à 8 max
}

/*
 * LE MODULO (%) - Pour comportement circulaire
 * 
 * 0 % 8 = 0
 * 1 % 8 = 1
 * ...
 * 7 % 8 = 7
 * 8 % 8 = 0  ← Revient au début !
 * 9 % 8 = 1
 * 
 * Donc add_index fait : 0 → 1 → 2 → ... → 7 → 0 → 1 → ...
 * Le 9ème contact remplace le 1er (le plus ancien)
 */


// ============================================================================
// 9. LOGIQUE SEARCH - Rechercher et afficher
// ============================================================================

void PhoneBook::search_contacts() const {
    // ÉTAPE 1 : Afficher le tableau formaté
    
    std::cout << std::setw(10) << "Index" << "|";  // setw(10) = largeur 10 caractères
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;
    
    for (int i = 0; i < current_index; ++i) {
        std::cout << std::setw(10) << i << "|";
        print_field(contacts[i].get_first_name());
        std::cout << "|";
        print_field(contacts[i].get_last_name());
        std::cout << "|";
        print_field(contacts[i].get_nickname());
        std::cout << std::endl;
    }
}

/*
 * std::setw(10) - Définit la largeur du champ
 *   - Par défaut aligné à DROITE
 *   - "John" avec setw(10) → "      John"
 *   - Besoin de #include <iomanip>
 */


// ============================================================================
// 10. TRONCATURE - Si le texte est trop long
// ============================================================================

void PhoneBook::print_field(const std::string& field) const {
    if (field.length() > 10)
        std::cout << field.substr(0, 9) << ".";  // "Alexandre" → "Alexandr."
    else
        std::cout << std::setw(10) << field;     // "John" → "      John"
}

/*
 * Exemple :
 *   "Jean"        →  "      Jean"  (aligné à droite, 10 chars)
 *   "Christopher" →  "Christoph."  (tronqué à 9 + point)
 */


// ============================================================================
// 11. VALIDATION DE L'INDEX
// ============================================================================

std::string input;
std::getline(std::cin, input);

// Vérifie si l'input est vide
if (input.empty()) {
    std::cout << "Invalid index." << std::endl;
    return;
}

// Convertit string → int avec stringstream
std::stringstream ss(input);
int index;
if (!(ss >> index)) {  // Échec si l'input n'est pas un nombre
    std::cout << "Invalid index." << std::endl;
    return;
}

// Vérifie s'il y a des caractères après le nombre (ex: "1abc")
std::string remainder;
ss >> remainder;
if (!remainder.empty()) {
    std::cout << "Invalid index." << std::endl;
    return;
}

// Vérifie la plage [0, current_index[
if (index < 0 || index >= current_index) {
    std::cout << "Index out of range." << std::endl;
    return;
}

/*
 * std::stringstream - Convertit entre types
 *   - Comme atoi() mais plus sûr
 *   - Détecte les erreurs de conversion
 *   - Besoin de #include <sstream>
 */


// ============================================================================
// 12. GESTION DE EOF (Ctrl+D)
// ============================================================================

std::getline(std::cin, command);

if (std::cin.eof()) {  // Détecte la fin du fichier (Ctrl+D)
    std::cout << std::endl;
    break;
}

/*
 * EOF (End Of File) :
 *   - Ctrl+D sur Linux/Mac
 *   - Ctrl+Z sur Windows
 *   - std::cin.eof() retourne true si EOF détecté
 */


// ============================================================================
// 13. DIFFÉRENCES C vs C++
// ============================================================================

/*
 * +-------------------+---------------------------+
 * |        C          |          C++              |
 * +-------------------+---------------------------+
 * | char* avec malloc | std::string (auto)        |
 * | struct            | class (avec fonctions)    |
 * | scanf, printf     | std::cin, std::cout       |
 * | Pointeurs         | Références (&) + simples  |
 * | typedef struct    | Directement class Name    |
 * | free()            | Destructeur automatique   |
 * +-------------------+---------------------------+
 */


// ============================================================================
// 14. POINTS CLÉS DU SUJET
// ============================================================================

/*
 * ✅ Pas de malloc/free
 *    → Tableau statique : Contact contacts[8]
 * 
 * ✅ Maximum 8 contacts
 *    → Remplacement circulaire avec modulo : add_index = (add_index + 1) % 8
 * 
 * ✅ Champs obligatoires (pas de champs vides)
 *    → Fonction is_valid() vérifie avec .empty()
 * 
 * ✅ Tableau formaté avec colonnes de 10 caractères
 *    → std::setw(10) pour l'alignement à droite
 * 
 * ✅ Troncature si texte > 10 caractères
 *    → field.substr(0, 9) + "." si trop long
 * 
 * ✅ Validation de l'index
 *    → Vérification nombre valide + plage correcte
 * 
 * ✅ 3 commandes : ADD, SEARCH, EXIT
 *    → Boucle infinie jusqu'à EXIT ou EOF
 */


// ============================================================================
// 15. EXEMPLE D'UTILISATION COMPLÈTE
// ============================================================================

int main() {
    PhoneBook phoneBook;  // Crée un PhoneBook (constructeur appelé)
    std::string command;
    
    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        
        if (std::cin.eof()) {
            std::cout << std::endl;
            break;
        }
        
        if (command == "ADD") {
            Contact newContact;  // Crée un Contact vide
            std::string input;
            
            // Demande chaque champ
            std::cout << "First Name: ";
            std::getline(std::cin, input);
            if (std::cin.eof())
                break;
            newContact.set_first_name(input);
            
            // ... pareil pour les autres champs
            
            // Vérifie et ajoute
            if (newContact.is_valid())
                phoneBook.add_contact(newContact);
            else
                std::cout << "All fields are required. Contact not added." << std::endl;
        }
        else if (command == "SEARCH") {
            phoneBook.search_contacts();
        }
        else if (command == "EXIT") {
            break;
        }
    }
    
    return 0;
    // Ici, phoneBook est détruit → destructeur appelé
    // Les 8 contacts sont aussi détruits → leurs destructeurs appelés
}

/*
 * ORDRE DE DESTRUCTION :
 *   1. phoneBook sort du scope (fin de main)
 *   2. Destructeur de PhoneBook appelé
 *   3. contacts[8] détruit → destructeur de chaque Contact appelé
 *   4. Destructeurs des std::string de chaque Contact appelés
 *   → Toute la mémoire est libérée automatiquement !
 */


// ============================================================================
// FIN DU COURS
// ============================================================================
