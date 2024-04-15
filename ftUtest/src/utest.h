#include<string>
#include<functional>
#include"ftutest_export.h"
#include<vector>


namespace ft {

	using UTestFuncPtr = std::function<void()>;



	struct UTest {
		UTest(std::string&& name, UTestFuncPtr f, std::string&& desc) :m_name(std::move(name)), m_desc(std::move(desc)), m_f(f) {}

		void DECLSPEC run()const;

		std::string m_name, m_desc;
		UTestFuncPtr m_f;

	private:
		void _run() const;
	};


	class UTests {
	public:
		static void add(UTest&& test) 
		{
			tests().emplace_back(std::move(test));
		}

		DECLSPEC static int runAll();

		struct REG {
			REG(std::string&& name, UTestFuncPtr const f, std::string&& desc) {
				add(UTest(std::move(name), f, std::move(desc)));
			}
		};
	private:
		DECLSPEC static std::vector<UTest>& tests();
	};


#define DEFINE_UNIT_TEST(name, desc) \
static void name();\
namespace\
{\
	UTests::REG s_ ## name(std::string(# name), (UTestFuncPtr) &name, std::string(desc)); \
}\
void name()



}; // namespace ft
