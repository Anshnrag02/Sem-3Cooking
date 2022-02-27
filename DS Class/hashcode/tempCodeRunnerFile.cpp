template <class T, class U, typename Hash = splitmix64_hash> using hash_map = gp_hash_table<T, U, Hash>;
// template <class T, typename Hash = splitmix64_hash> using hash_set = hash_map<T, null_type, Hash>;
