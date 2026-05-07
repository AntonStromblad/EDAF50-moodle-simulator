#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <iterator>

// Uppgift 1a: invert_map
// Skriv en funktionsmall invert_map som tar en std::map<K, V> 
// och returnerar en std::map<V, K> (inverterad map).

// Din kod för invert_map här...


// Uppgift 1b: bidir_map
// Skriv en klassmall bidir_map<K, V> som ärver från std::map<K, V>.
// Den ska fungera precis som std::map, men ha en extra överlagring av
// funktionen 'at' som gör en reverse-lookup (letar upp nyckeln för ett givet värde).

// Uppgift 1c: reverse find (i bidir_map)
// Lägg till en överlagring av funktionen 'find' i bidir_map.
// Den ska ta ett värde och returnera ett std::pair av iteratorer (start och slut)
// som pekar på alla nycklar som är mappade till just det värdet.
// Tips: Du kommer behöva skriva en egen iterator för detta!

// Din kod för bidir_map här...