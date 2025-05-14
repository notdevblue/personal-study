public class Program
{
    public static void Main(string[] inArgs)
    {
        var square = MathHelper.Square(10);
        System.Console.WriteLine(square);

        var coffee = new CoffeeHandler(new Coffee() { Name = "Espresso" });
        var coffeeName = coffee.GetCoffeeName();
        System.Console.WriteLine(coffeeName);

        var letterDispatcher = new LetterDispatcher();
        letterDispatcher.Dispatch("A");
        letterDispatcher.Dispatch("B");
        letterDispatcher.Dispatch("C");

        var myButton = new Button();
        myButton.AddListener(() => System.Console.WriteLine("Click!"));
        myButton.Click();
    }

    // 반복적인 코드 (거의 의존성 없는거들) 묶어둠
    // 보통 맴버 변수 없음. (상태 X) 함수만 가진게 일반적
    // * 예상하지 못한 사이드 이팩트 발생 가능
    // * 재사용하기 힘듬 -> 동일한 입력 동일한 결과 보장 안됨
    // * 여러 곳에서 동시에 사용하기 힘듬 (스레드)
    // * context 의존 -> 이전 호출 이후 호출 등...
    public static class MathHelper
    {
        public static long Square(int inNum)
        {
            return inNum * inNum;
        }

        public static bool IsBelowZero(int inNum)
        {
            return inNum < 0;
        }

        public static long GetSquareTriangularSideLength(int inWidth, int inHeight)
        {
            var inSquareLength = Square(inWidth) * Square(inHeight);
            return inSquareLength;
        }
    }

    // 어떠한 행위 (요청, 이벤트 등) 을 받아 처리함.
    // 콜백 함수의 클래스 버전
    // (ChatGPT 기준 SRP 여야 함. 콜백 함수의 클래스 버전이니... 아래가 허용은 되긴 하는데 그래도..)
    public class CoffeeHandler
    {
        private readonly Coffee _coffee;

        public CoffeeHandler(Coffee inCoffee)
        {
            _coffee = inCoffee;
        }

        public Coffee GetCoffee()
        {
            return new Coffee(_coffee);
        }

        public string GetCoffeeName()
        {
            return _coffee.Name;
        }
    }
    public class Coffee
    {
        public string Name { get; set; } = "";

        public Coffee(Coffee inOtherCoffee)
        {
            Name = inOtherCoffee.Name;
        }

        public Coffee() { }
    }

    // 명령, 이벤트 요청 등을 적절한 처리기 (Handler) 로 보내는 역할을 가짐
    // 이벤트나 요청을 적절한 핸들러로 전달
    // 이거도 엄청나게 큰 관점으로 보면 요청을 처리한다 라는 개념이라 핸들러라고 할 수는 있지만, 실제로 처리하는건 아니고, 요청을 받아 처리하는 쪽으로 전달하는 역할이니 핸들러라고 할 수는 없음
    public class LetterDispatcher
    {
        private Dictionary<string, IHandler> _inputToHandler = new()
        {
            { "A", new AHandler() },
            { "B", new BHandler() },
            { "C", new CHandler() }
        };

        public void Dispatch(string inInput)
        {
            if (_inputToHandler.TryGetValue(inInput, out var foundHandler))
            {
                foundHandler.Handle();
            }
            else
            {
                throw new NotImplementedException("NotImplementedHandler");
            }
        }
    }
    public interface IHandler { public void Handle(); };
    public class AHandler : IHandler { public void Handle() { System.Console.WriteLine(typeof(AHandler).ToString()); } };
    public class BHandler : IHandler { public void Handle() { System.Console.WriteLine(typeof(BHandler).ToString()); } };
    public class CHandler : IHandler { public void Handle() { System.Console.WriteLine(typeof(CHandler).ToString()); } };

    // 특정 조건이 만족되었을 때 발생하는 동작
    // 조건, 행동, 연결. 작동할 특정한 조건, 조건 만족 시 실행할 행동, 조건과 행동의 연결 고리
    // 실질적으로는 조건, 행동을 가짐
    public class Button // Trigger
    {
        public Action OnButtonClicked { get; set; } = () => { }; // 트리거가 실행할 행동

        public void Click() // 트리거가 실행될 시점
        {
            OnButtonClicked.Invoke();
        }

        public void AddListener(Action onButtonClicked) => OnButtonClicked += onButtonClicked;
    }
}