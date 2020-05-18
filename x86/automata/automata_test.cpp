//
// Created by toohoo on 16/5/2020.
//
/*
 * 基于表驱动的词法分析有限自动机实现
 */
cur_char = ' ';                                 // 初始字符为空格
Token* Lexer::tokenize(){                       // 词法记号解析
    cur_state = 0;                              // 初始状态为0
    while(1){                                   // 启动有限自动机
        next_state = table[cur_state, cur_char];// 查表获取下一个状态
        if(next_state == accept){               // 接受状态
            return process(cur_state);          // 处理接受状态
        }
        else if(next_state == error){           // 错误状态
            return lex_error(cur_state, cur_char); // 词法错误处理
        }
        else{
            handle_status(cur_state, cur_char); // 处理当前状态
            cur_state = next_state;             // 进入下一个状态
            cur_char = scan(file);              // 扫描获取下一个字符
        }
    }
}

// 硬编码方式的词法分析
if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch == '_'){
    string name = "";                             // 接收的是一个字符串
    do{
        name.push_back(ch);                         // 记录字符
        scan();                                     // 读入字符
    } while(ch>='a' && ch <= 'z' || ch >= 'A' && ch <= 'Z'
    ||ch == '_'||ch >= '0' && ch <= '9');           // 匹配结束
    Tag tag = keywords.getTag(name);                // 查询关键字
    if(tag == ID)                                   // 正常的标识符
        t = new Id(name);                           // 创建标识符
    else
        t = new Token(tag);
}

/**
 * 关键字列表初始化
 */
Keywords::Keywords(){
    keywords["int"] = KW_INT;
    keywords["char"] = KW_CHAR;
    keywords["void"] = KW_VOID;
    keywords["extern"] = KW_EXTERN;
    keywords["if"] = KW_IF;
    keywords["else"] = KW_ELSE;
    keywords["switch"] = KW_SWITCH;
    keywords["case"] = KW_CASE;
    keywords["default"] = KW_DEFAULT;
    keywords["while"] = KW_WHILE;
    keywords["do"] = KW_DO;
    keywords["for"] = KW_FOR;
    keywords["break"] = KW_BREAK;
    keywords["continue"] = KW_CONTINUE;
    keywords["return"] = KW_RETURN;
}
/*
 * 测试是否是关键字
 */
Tag Keywords::getTag(string name){
    return keywords.find(name) != keywords.end()?keywords[name]:ID;
}
