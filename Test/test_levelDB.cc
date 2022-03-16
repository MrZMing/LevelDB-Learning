#include <cassert>
#include <iostream>
#include <string>
#include <leveldb/db.h>

int main() {
	    
	    leveldb::DB* db; 
	    leveldb::Options options;
	    // 配置项：如果LevelDB数据库目录不存在，则自动创建
	    options.create_if_missing = true;
	        
	        leveldb::Status status = leveldb::DB::Open(options, "/root/testdb", &db);
		    
		    assert(status.ok());

		        std::string key = "apple";
			    std::string value = "Apple";
			    leveldb::Status s = db->Put(leveldb::WriteOptions(), key, value);

			        std::string get;
				if(s.ok()) {
					        s = db->Get(leveldb::ReadOptions(), key, &get);
						    }   
				    if(s.ok()) {
					            std::cout << "读取到Key=" << key << "对应的Value=" << get << "." << std::endl;
						        } else {
								        std::cout << "读取失败！" << std::endl;
									    }   

				        delete db; 

					    return 0;
}
