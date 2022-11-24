#include <gtest/gtest.h>

#include "hashmap_open_hashing.hpp"

TEST(HashMapOpenHashing, Insert_Simple) {
  HashMap<std::string, std::string> h;

  h.insert("key1", "value1");
  h.insert("key2", "value2");
  h.insert("key3", "value3");

  EXPECT_EQ(h.size(), 3);
  EXPECT_EQ(*h.find("key1"), "value1");
  EXPECT_EQ(*h.find("key2"), "value2");
  EXPECT_EQ(*h.find("key3"), "value3");
}

TEST(HashMapOpenHashing, Find_NotFound) {
  HashMap<std::string, std::string> h;

  h.insert("key1", "value1");
  h.insert("key2", "value2");
  h.insert("key3", "value3");

  EXPECT_EQ(h.find("key4"), nullptr);
  EXPECT_EQ(h.find("f"), nullptr);
  EXPECT_EQ(h.find("key0"), nullptr);
}

TEST(HashMapOpenHashing, Erase_NotFound) {
  HashMap<std::string, std::string> h;
  h.insert("key1", "value1");
  h.insert("key2", "value2");
  h.insert("key3", "value3");

  EXPECT_EQ(h.erase("key4"), false);
  EXPECT_EQ(h.size(), 3);
  EXPECT_EQ(h.erase("f"), false);
  EXPECT_EQ(h.size(), 3);
  EXPECT_EQ(h.erase("key0"), false);
  EXPECT_EQ(h.size(), 3);
}

TEST(HashMapOpenHashing, Erase_Found) {
  HashMap<std::string, std::string> h;
  h.insert("key1", "value1");
  h.insert("key2", "value2");
  h.insert("key3", "value3");

  EXPECT_EQ(h.erase("key1"), true);
  EXPECT_EQ(h.find("key1"), nullptr);
  EXPECT_EQ(h.size(), 2);

  EXPECT_EQ(h.erase("key3"), true);
  EXPECT_EQ(h.find("key3"), nullptr);
  EXPECT_EQ(h.size(), 1);

  EXPECT_EQ(h.erase("key2"), true);
  EXPECT_EQ(h.find("key2"), nullptr);
  EXPECT_EQ(h.size(), 0);
}