#include <iterator>

// Uppgift 1: Implementera remove_if.
// Den ska flytta alla element som INTE uppfyller predikatet 'pred' till början av sekvensen.
// Returnera en iterator till positionen efter det sista giltiga elementet.

template <typename ForwardIterator, typename UnaryPredicate>
ForwardIterator my_remove_if(ForwardIterator first, ForwardIterator last, UnaryPredicate pred) {
    // Din kod här!
    // Tips: Hitta första elementet som ska tas bort, 
    // flytta sedan nästa element som ska BEHÅLLAS till den positionen.
}