% In this code you have to click above the figure
set(gcf,'CurrentCharacter',' ') % empty current character
while true
    pos = get(0, 'PointerLocation');
    x = pos(1);
    y = pos(2);

      % Determina o quadrante numérico (para usar no switch)
    if x <= 800 && y >= 451
        q = 1;  % Quadrante A
    elseif x >= 801 && y >= 451
        q = 2;  % Quadrante B
    elseif x <= 800 && y <= 450
        q = 3;  % Quadrante C
    elseif x >= 801 && y <= 450
        q = 4;  % Quadrante D
    end

    % Usa switch para imprimir o quadrante
    switch q
        case 1
            quadrante = 'A';
        case 2
            quadrante = 'B';
        case 3
            quadrante = 'C';
        case 4
            quadrante = 'D';
    end

    clc;  % Limpa o console
    fprintf('Posição do mouse: x=%d, y=%d - Quadrante: %s\n', x, y, quadrante);



    figure(1)
    % Adjust the delay as needed
    tic
    while toc<0.01
        ch = get(gcf,'CurrentCharacter');
    end
    if double(ch) == 27
        break
    end
end
