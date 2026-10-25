// Exercise (C++14): Find assets without constructing temporary keys.
// Index asset records by name while accepting lightweight C-string lookup keys.
//
// Tasks:
// 1. Complete AssetLess with an is_transparent type alias and the three declared
//    comparison overloads.
// 2. Compare names lexicographically for Asset/Asset, Asset/const char*, and const
//    char*/Asset. The same name must compare equivalent regardless of the other fields.
// 3. Compare C-string probes directly with stored strings without creating temporary
//    Asset or string objects. Assume probes are non-null, null-terminated strings and
//    names contain no embedded nulls.
// 4. Keep the set and find calls unchanged: heterogeneous lookup must find a const
//    char* key in a set of Asset objects.
//
// Background:
// - A transparent comparator advertises an is_transparent nested type. Its presence
//   enables C++14 associative-container lookup overloads for other key types.
// - The marker does not implement comparison: the comparator must accept both stored-
//   key/probe and probe/stored-key operands with one consistent strict weak ordering.
// - std::string supports comparisons with C strings without first constructing another
//   std::string. std::string_view is not available in C++14.
//
// Checks: Check successful and missing probes, lexical ordering, equal-name records,
// and empty keys.
// The starter is intentionally unfinished and will not compile or link yet.
//
// Enable, build, and test from the repository root:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP14_HETEROGENEOUS_LOOKUP=ON
// cmake --build --preset gcc-debug --target exercise_cpp14_heterogeneous_lookup
// ctest --preset gcc-debug -R '^exercise_cpp14_heterogeneous_lookup$'
//
// Disable again:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP14_HETEROGENEOUS_LOOKUP=OFF

#include <cassert>
#include <cstddef>
#include <set>
#include <string>
#include <type_traits>

struct Asset { std::string name; std::size_t bytes; };

struct AssetLess {
    // TODO: Add the transparency marker and implement these comparisons.
    bool operator()(const Asset& left, const Asset& right) const;
    bool operator()(const Asset& left, const char* right) const;
    bool operator()(const char* left, const Asset& right) const;
};

int main() {
    static_assert(!std::is_convertible<const char*, Asset>::value, "probe is not an Asset");
    std::set<Asset, AssetLess> assets{{"logo.svg", 512}, {"config.json", 128}, {"index.html", 2048}};
    const auto& catalog = assets;
    const auto found = catalog.find("logo.svg");
    assert(found != catalog.end() && found->bytes == 512);
    assert(catalog.find("missing") == catalog.end());
    assert(catalog.find("") == catalog.end());
    assert(catalog.begin()->name == "config.json");
    const auto duplicate = assets.insert(Asset{"logo.svg", 999});
    assert(!duplicate.second && duplicate.first->bytes == 512);
    const std::string query = "index.html";
    const auto index = catalog.find(query.c_str());
    assert(index != catalog.end() && index->bytes == 2048);
    assets.insert(Asset{"", 0});
    assert(catalog.find("") == catalog.begin());
    const AssetLess less;
    assert(!less(Asset{"same", 1}, Asset{"same", 2}));
    assert(!less(Asset{"same", 1}, "same") && !less("same", Asset{"same", 1}));
}
